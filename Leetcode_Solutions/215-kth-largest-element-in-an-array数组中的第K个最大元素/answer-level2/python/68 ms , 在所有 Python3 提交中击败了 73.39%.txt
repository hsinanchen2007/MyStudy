### 解题思路
冒泡, 快排, 堆排序, partition
自己写的冒泡O(nlogk)通不过, 然后内置函数快排(O(nlogn)就过了, 打败90%, 内置函数牛批
然后自己又写了个堆排序过了, 打败73%. 这里要维护一个小顶堆, 即堆顶元素是前K大中最小的

### 代码

```python3
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def add(n):
            if len(heap)<k+1: # 元素插入, 插入到最后然后bottom_up
                heap.append(n)
                i = len(heap)-1
                while i//2:
                    if heap[i//2]>heap[i]:
                        heap[i//2], heap[i] = heap[i], heap[i//2]
                        i //= 2
                    else: break             
            elif n>heap[1]: # 堆调整
                heap[1] = n
                i = 1
                while i*2<k+1: # 用左孩子去碰临界
                    tmp = i
                    # if i*2+1<k+1 and heap[i*2]<heap[i*2+1]: # 一开始写的太乱太垃圾了
                    #    if heap[i]>heap[i*2]:
                    #        heap[i], heap[i*2] = heap[i*2], heap[i]
                    #        i = i*2
                    #        continue
                    # else:
                    #     if heap[i]>heap[i*2+1]:
                    #         heap[i], heap[i*2+1] = heap[i*2+1], heap[i]
                    #         i = i*2+1
                    #         continue
                    if i*2+1<k+1 and heap[i*2]>heap[i*2+1]: # 直接获取应该交换的index, 避免了重复的代码, 和上面好好比较下!!!!
                        i = i*2+1
                    else:
                        i = i*2
                    if heap[tmp]>heap[i]:
                        heap[tmp], heap[i] = heap[i], heap[tmp]
                    else: break 
        heap = [0] #  加了个无用元素0, 相当于堆的索引从1开始, 那么左右孩子就是2*i, 2*i+1, 也可以从0开始, 左右孩子就是2*i+1, 2*i+2
        for n in nums:
            add(n)
        return heap[1]
```

又练习了一下partition的写法, beat 83
每次经过一次partition后, 比pivot大的都在右边, 如果right-pivot_index等于k, 则pivot就是要找的值, 
否则若右边个数大于k, 则在[pivot_index+1, right)的范围内重复partition去找第k大的数;
若右边个数right-pivot_index小于k, 则在[left, pivot]的范围内重复partition找第k-(right-pivot_index)大的数

```

class Solution:
    def findKthLargest(self, nums, k: int) -> int:
        def partition(left, right, pivot):
            nums[pivot], nums[right-1] = nums[right-1], nums[pivot]
            i, j = left, right-2
            while True:
                while i<=j and nums[j]>=nums[right-1]: j-=1
                while i<=j and nums[i]<nums[right-1]: i+=1 # i指向的一定是严格小于pivot且有效的. (i最大等于right-1, 然而j最小可以为-1)
                if i<=j: nums[i], nums[j] = nums[j], nums[i]
                else: break
            # nums[pivot], nums[i] = nums[i], nums[pivot] # 注意这时候pivot已经交换到最后一位了
            nums[right-1], nums[i] = nums[i], nums[right-1] # 由上述所以每次结束pivot都和i交换
            return i

        def select(left, right, k): # 这里的right的长度而非index
            if right-left==1 or left==right: #left==right 是只有partition时1个元素时的特例
                return nums[left]
            pivot = random.randint(left, right-1) # 生成[left,right-1]的随机数而非[left, right-1)
            pivot_index = partition(left, right, pivot)
            if right-pivot_index==k:
                return nums[pivot_index]
            elif right-pivot_index>k:
                return select(pivot_index+1, right, k) # 这里+1是为了避免无限循环, 否则三个参数可能会一直不变, 这样可能会导致只有1个元素进行partition, 所以前面也要加left==right去判断
            else:
                return select(left, pivot_index, k-(right-pivot_index)) # 这里pivot_index就不用+1了
        l = len(nums)        
        return select(0, l, k)
```
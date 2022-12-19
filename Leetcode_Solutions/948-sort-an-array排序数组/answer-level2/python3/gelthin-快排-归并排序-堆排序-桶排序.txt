### 解题思路
+ 快排  [506. 相对名次](https://leetcode-cn.com/problems/relative-ranks/)
+ 归并排序 代码有更加优雅地写法，在先前哪道题的题解中有看到过
+ 堆排序 这个主要来自于 《算法4》 课本 
+ 桶排序 使用一个计数数组简单计数

python 写快排时发现的一个 BUG:
+ self.sortArray(nums[left:i]) 这样传递的是副本，在函数内部修改 nums， 不会影响到外面的变量
+ quicksort(nums, left, i-1) 这样 nums 才是直接传引用的
例如下面的示例代码：
``` python3
In: A = [1,2,3,4]
In: def B(A):
        A[1] = 100
In: B(A)
In: A
Out: [1, 100, 3, 4]
In: B(A[1:])  # A[:] 也是类似的效果，传的是副本（copy）
In: A
Out: [1, 100, 3, 4]
```


官方题解的快排 类似于 童老师所讲的快排，i 先初始化为 left-1, 然后重复 i += 1
我更习惯于 i 初始化为 left。

官方题解的堆排序代码比较冗余，不过把功能都抽象出来了，看上去易懂。

### 代码
``` python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        ## 练习 快排，堆排序，归并排序
        # 
        def partition(nums, left, right): # [left, right] 闭区间
            import random
            ind = random.choice(range(left, right+1))  # 随机选一个，避免退化
            nums[ind], nums[right] = nums[right], nums[ind]

            x = nums[right]
            i = left
            for j in range(left, right): # 不考虑 nums[right]
                if nums[j] < x:
                    nums[i], nums[j] = nums[j], nums[i]
                    i += 1
            nums[i], nums[right] = nums[right], nums[i]
            return i
        
        def sort(nums, left, right): # 若传递 nums[left:right+1], 其实传的是副本
            i = partition(nums, left, right)
            if left<i-1:
                sort(nums, left, i-1) 
            if i+1<right:
                sort(nums, i+1, right)
            return nums

        sort(nums, 0, len(nums)-1)
        # left, right = 0, len(nums)-1
        # i = partition(nums, left, right)
        # if left<i-1:
        #     self.sortArray(nums[left:i])  # 这里有 bug?, 传递参数 nums[:2] 其实传的是复制
        # if i+1<right:
        #     self.sortArray(nums[i+1:right+1])
        return nums
        
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def merge(A, B):
            C = []
            i, j = 0, 0
            while i<len(A) and j<len(B):
                if A[i] <= B[j]: # 稳定性
                    C.append(A[i])
                    i += 1
                else:
                    C.append(B[j])
                    j += 1
            if i < len(A):  # 这一段代码有更加优雅地写法，在先前哪里看到过
                C += A[i:]
            if j < len(B):
                C += B[j:]
            return C 

        def mergesort(nums, left, right):
            if right-left<1:
                return nums[left:right+1]  # 这里很微妙， 易错
            ind = left + (right-left)//2
            A = mergesort(nums, left, ind)
            B = mergesort(nums, ind+1, right)
            return merge(A, B)
        return mergesort(nums, 0, len(nums)-1)

### 照着算法-第四版-书写的。
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        # 堆排序
        def sink(A, i, m):  # 小值往下沉，大顶堆
            while 2*i <= m:
                j = 2*i 
                if j<m and A[j]<A[j+1]:
                    j += 1
                if A[i] > A[j]:
                    break
                A[i], A[j] = A[j], A[i]
                i = j

        def heapsort(A):
            m = len(A)-1 # 有效长度
            k = m//2
            # 建堆
            while k>=1:
                sink(A, k, m)
                k -= 1

            # 堆排序
            i = 1
            while m >1:
                A[i], A[m] = A[m], A[i]
                m -= 1
                sink(A, 1, m)
        
        A = [0]+nums
        heapsort(A)
        return A[1:]

#### 自己关上书重写的代码，写出了 BUG 并纠正
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def sink(nums, i, N):  # 大顶堆，小的往下沉
            # j = 2*i BUG： 下面 j 没更新
            while 2*i <= N: # 一直处理到这个节点没有子节点
                j = 2*i # i 的子节点 2*i, 2*i+1
                if j<N and nums[j]<nums[j+1]:
                    j += 1
                if nums[i]>=nums[j]:
                    break
                # nums[i], nums[j] == nums[j], nums[i] bug
                nums[i], nums[j] = nums[j], nums[i]
                i = j

        def heapsort(nums): # 用下标 1 开始存储数字
            N = len(nums)-1
            k = N//2 # 从堆的最后一个非叶子节点开始建堆
            
            # 建一个大顶堆
            while k>=1:
                sink(nums, k, N)
                k -= 1
            # 堆排序
            while N > 1:
                nums[1], nums[N] = nums[N], nums[1]
                N -= 1
                sink(nums, 1, N)
            #return nums
        
        # A = [0] + nums
        # heapsort(A)
        # return A[1:]
        nums = [0] + nums
        heapsort(nums)
        return nums[1:]


class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        ### 简单桶排序
        bucket = [0]*(10**5+1)
        for x in nums:
            bucket[x+50000] += 1
        result = []
        for i in range(len(bucket)):
            result += [i-50000]*bucket[i]
        return result
```
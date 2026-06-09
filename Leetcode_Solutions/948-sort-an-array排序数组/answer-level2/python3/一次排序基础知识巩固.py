### 解题思路
现在大家排序都是直接流氓，sort一般是用快排写的，collections里把堆排序也写了

但是既然这是一道中等题，尊重一下，手写一下基础常用的一些算法

快排，堆排序，归并排序

### 代码

```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        # 流氓法
        # return sorted(nums)
    
        # 快速排序
        # 这里用了一种新的快排思路
        # 先把pivot放到最右边
        
        # 返回划分的位置
#         def random_partition(nums,l,r):
#             pivot = random.randint(l,r)
#             nums[pivot], nums[r] = nums[r],nums[pivot]
#             i = l-1
#             for j in range(l,r):
#                 if nums[j] < nums[r]:
#                     i += 1
#                     nums[i],nums[j] = nums[j],nums[i]
            
#             nums[i+1],nums[r] = nums[r], nums[i+1]
            
#             return i+1
        
#         def random_quick_sort(nums,l,r):
#             if r <= l:
#                 return 
#             mid = random_partition(nums,l,r)
#             random_quick_sort(nums,l,mid-1)
#             random_quick_sort(nums,mid+1,r)
            
#         random_quick_sort(nums,0,len(nums)-1)
#         return nums


        # 堆排序
        # 就不耍流氓了，手写一遍巩固一下
        
        # 首先是一个调整函数，能把root调整到正确的位置，调整的过程是自顶向下的
#         def max_heapify(heap,root,heap_len):
#             p = root
#             # 当有孩子的时候
#             while(p*2+1 < heap_len):
#                 l, r = p*2+1, p*2 +2
#                 # 当右边孩子不存在，否则就比较，让指针选择那个比较大的子节点
#                 if heap_len <= r or heap[r] < heap[l]:
#                     nex = l
#                 else:
#                     nex = r
#                 # 如果根节点比选择节点要小的话，说明需要进行调整，交换他们的值，用指针跟踪这个根节点现在的位置
#                 if heap[p] < heap[nex]:
#                     heap[p],heap[nex] = heap[nex],heap[p]
#                     p = nex
#                 else:
#                     break
              
#         def build_heap(heap):
#             # 一个个插入去建树，每次都需要调整,建立的过程因为是用数据去存树的，所以要从后往前去建立
#             for i in range(len(heap)-1,-1,-1):
#                 # 调整的范围是从慢慢增加的元素到最后
#                 max_heapify(heap,i,len(heap))
                
                
#         def heap_sort(nums):
#             # 把数组穿进去，调用建立堆
#             build_heap(nums)
#             # 每一次把最后的元素和堆顶交换,长度减1，调整
#             for i in range(len(nums)-1,-1,-1):
#                 nums[i],nums[0] = nums[0],nums[i]
#                 max_heapify(nums,0,i)
        
#         heap_sort(nums)  
#         return nums


        # 最后复习一下归并排序
        def merge_sort(nums,l,r):
            if l == r: 
                return 
            
            mid = l + (r-l)//2
            merge_sort(nums,l,mid)
            merge_sort(nums,mid+1,r)
            
            # 然后把这两段有序的序列线性合并，两个指针分别指示两个序列当前归并到哪个位置
            tmp = []
            i, j = l, mid + 1
            while(i <= mid and j <= r):
                if nums[i] <= nums[j]:
                    tmp.append(nums[i])
                    i += 1
                else:
                    tmp.append(nums[j])
                    j += 1
            
            if(i<=mid):
                for _ in range(i,mid+1):
                    tmp.append(nums[_])
            if(j<=r):
                for _ in range(j,r+1):
                    tmp.append(nums[_])
            
            nums[l:r+1] = tmp
        
        merge_sort(nums,0,len(nums)-1) 
        return nums
                
            
            
```
### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def merge_sort(nums):
            if len(nums)<2:
                return nums
            mid=len(nums)//2
            l=nums[:mid]
            r=nums[mid:]
            left=merge_sort(l)
            right=merge_sort(r)
            return merge(left,right)
        def merge(l,r):                 #将l,r进行合并的函数
            result=[0]*(len(l)+len(r))  #记录最后的结果
            i,j=0,0                     #i表示l的索引，j表示r的索引
            while i+j<(len(l)+len(r)):
                if j==len(r) or (i<len(l) and l[i]<=r[j]):
                    result[i+j]=l[i]
                    i+=1
                else:
                    result[i+j]=r[j]
                    j+=1
            return result
        return merge_sort(nums)

```

```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        l,r=0,len(nums)-1

        def position(l,r):
            target=nums[l]
            while l<r:
                while l<r and nums[r]>target:
                    r-=1
                nums[l]=nums[r]
                while l<r and nums[l]<=target:
                    l+=1
                nums[r]=nums[l]
            nums[l]=target
            return l
        def sort(l,r):
            if l>=r:
                return
            mid=position(l,r)
            sort(l,mid-1)
            sort(mid+1,r)
        sort(l,r)
        return nums

```

```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def heapify(nums, root, n):
            """定义一个heapiy函数，主要功能是以某个节点为根节点构建一个节点的局部大顶堆"""
            if root * 2 + 1 > n:  #注意，递归出口，当没有子节点时出去,这里n是最后一个元素的索引
                return
            maxindex = root        #记录根节点和左右节点三者中大者的索引，初始化为根节点
            # 注意这里时三个if，不是if else ，因为三个点要互相比较找到最大的
            if root * 2 + 1 <= n and nums[root * 2 + 1] > nums[maxindex]:
                maxindex = root * 2 + 1
            if root * 2 + 2 <= n and nums[root * 2 + 2] > nums[maxindex]:
                maxindex = root * 2 + 2
            if maxindex != root:     #如果最大索引不是最先的root索引了，说明变了
                nums[root], nums[maxindex] = nums[maxindex], nums[root]
                #把最大值交换到根节点，再对交换的那边做heapify，没有交换的不动
                heapify(nums, maxindex, n)   #注意这里值交换了，索引没有变，

        #构建大顶堆
        n = len(nums)-1  #这里n是最后一个元素索引
        for i in range((n - 1 )// 2 , -1, -1):  #从最后一个父节点开始heapify，到顶点就会构建成一个大顶堆
            heapify(nums, i, n)

        # 把堆顶和堆未交换，再把最后一个点，即最大值剔除，再又一次建堆
        while n>0:
            nums[0],nums[n]=nums[n],nums[0]
            n-=1         #相当于剔除最后一个元素
            heapify(nums,0,n)
        return nums

```
### 解题思路
和<27移除元素>类似，通过pop()或双指针可以实现
#### 1.pop()
删除元素为了不破坏索引，删除pop(i)操作从后向前执行。
#### 2.双指针（快慢指针）：
慢指针L指向满足的元素（不重复元素或重复元素的首元素），快指针R寻找非重复的元素，初始`L,R=0,1`
### 代码1 --从后向前pop(i)
```python3
#给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
#不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        #和27移除元素相似
        #直接删除
        n=len(nums)
        for i in range(n-1,0,-1):#反向搜索,并删除后面相同元素
            if nums[i]==nums[i-1]:
                nums.pop(i)
                n-=1
        return n
```


### 代码2 --双指针

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        #和27移除元素相似
        #双指针
        n=len(nums)
        if n<2:return n
        L,R=0,1
        while R<n and L<n:
            if nums[R]==nums[L]:#快指针寻找不等元素
                R+=1
            elif nums[R]!=nums[L]:#若不等，将不等的元素覆盖（或交换）掉慢指针的右元素（保留重复元素的首元素）
                nums[L+1]=nums[R]
                R+=1#L/R同步移动
                L+=1
        return L+1#L指向重复元素的首元素或不重复元素
```
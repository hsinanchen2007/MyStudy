### 解题思路
基于partition函数，实现时间复杂度为O(N)，改变了原始数组的顺序

### 代码

```python
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if not arr or k<0: return False
        if k==0: return []
        start,end=0,len(arr)-1
        index=self.partition(arr,len(arr),start,end)
        print(index)
        while index!=k-1:
            if index>k-1:
                end=index-1
                index=self.partition(arr,len(arr),start,end)
            else:
                start=index+1
                index=self.partition(arr,len(arr),start,end)
        return sorted(arr[:index+1])#这个答案有bug,输出的k个数，可以没有顺序,所以手工加了排序

    def partition(self,arr: List[int],length:int,start:int,end:int)-> int:
        if not List or start<0 or end>length-1:
            return False
        pivot=arr[start]#选择第一个作为基准
        arr[start],arr[end]=arr[end],arr[start]#交换基准与最后一个元素的位置
        small=start-1
        for i in range(start,end):
            if arr[i]<pivot:
                small+=1
                if small!=i:#不等于说明在上一个small出现arr[i]>pivot:
                    arr[small],arr[i]=arr[i],arr[small]
        small+=1
        arr[small],arr[end]=arr[end],arr[small]
        return small

        
```
### 解题思路
此处撰写解题思路
掌握标准的快速排序还是很有必要的
### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        #快速排序
        def quicksort(start,end):
            p=start
            q=end
            if end-start<=1:
                return
            label=arr[start]
            while start<end:
                while arr[end]>=label and end>start:
                    end-=1
                arr[end],arr[start]=arr[start],arr[end]
                while arr[start]<=label and end>start:
                    start+=1
                arr[end],arr[start]=arr[start],arr[end]
            arr[start]=label
            quicksort(p,start)
            quicksort(start+1,q)
        start=0
        end=len(arr)-1
        quicksort(start,end)
        return arr[:k]
```
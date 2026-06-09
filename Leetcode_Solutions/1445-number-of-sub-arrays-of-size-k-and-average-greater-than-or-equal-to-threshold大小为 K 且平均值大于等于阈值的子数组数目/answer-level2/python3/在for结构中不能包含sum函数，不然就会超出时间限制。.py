### 解题思路
此处撰写解题思路
在for结构中不能包含sum函数，不然就会超出时间限制。
### 代码

```python3
class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        n=0
        t=k*threshold
        for i in range(len(arr)-k+1):
            if i==0:
                arr_list= arr[i:k+i]
                sumarr=sum(arr_list)
            else:
                sumarr=sumarr-arr[i-1]+arr[i+k-1]
            if sumarr>=t:
                n += 1
          
        return n

```
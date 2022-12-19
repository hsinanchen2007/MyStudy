### 解题思路
只要注意首位是0和结尾是0的情况就可以了

### 代码

```python3
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        if not seats:
            return 
        maxDise=0
        size=len(seats)
        i=0
        flag=0 #首位是0的情况
        while i<size:
            cnt=0
            while i<size and seats[i]==1:
                i+=1
                flag+=1
            while i<size and seats[i]==0:
                cnt+=1
                i+=1
            if (i==size and seats[i-1]==0) or flag==0:
                maxDise=max(maxDise, cnt)  #首位是0 或者 结尾是0的情况
            else:
                maxDise=max(maxDise, (cnt+1)//2)
        return maxDise





```
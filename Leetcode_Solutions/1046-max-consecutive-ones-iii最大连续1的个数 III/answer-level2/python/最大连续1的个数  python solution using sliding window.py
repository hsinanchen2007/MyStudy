### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        output = 0
        winstart = 0
        repeat_one = 0

        for winend in range(len(A)):
            if A[winend] ==1:
                repeat_one +=1
            
            if winend-winstart+1 - repeat_one >K:
                if A[winstart] ==1:
                    repeat_one -=1
                winstart +=1
            output = max(output,winend-winstart+1)
        return output
            
        
```



Using the Sliding window method for this method ,very nice
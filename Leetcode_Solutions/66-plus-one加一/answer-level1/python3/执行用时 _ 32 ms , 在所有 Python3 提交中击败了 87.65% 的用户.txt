### 解题思路
1:digits变int
2:digits+1
3.digits变列表
### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num=''
        the_return=[]
        for i in digits:
            num=num+str(i)
        num=int(num)+1
        for i in str(num):
            i=int(i)
            the_return.append(i)
        return the_return
        
```
### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        #两个指针一头一尾  l*l+r*r和c比较
        l=0
        r=int(c**0.5)+1
        # 当等于2时，需要等于
        while l<=r:
            target=l*l+r*r
            if target==c:
                return True
            elif target<c:
                l+=1
            else:
                r-=1
        return False
```
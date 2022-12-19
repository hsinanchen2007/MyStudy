### 解题思路
用 ans 迭代取出的每位数进行平方求和，再判断是否已经出现过这个 ans ，是则 False,否则
放入集合，循环开始判断 ans 是否为1。
### 代码

```python3
class Solution:
    def isHappy(self, n: int) -> bool:
        
        ans = 0
        res = set()
        while n or ans:                 # --------n为正整数或者求和结果为真
            if not n:                   # --------若n已经取余完且为0
                if ans == 1:            # --------如果ans为1返回True
                    return True
                if ans not in res:      # --------如果ans没有出现过则加入集合
                    res.add(ans)
                else:                   # --------ans有出现过说明进入了死循环，返回False
                    return False
                n , ans = ans , n       # --------将 n , ans 互换重新开始下一轮循环
            ans += (n%10) ** 2
            n //= 10
```
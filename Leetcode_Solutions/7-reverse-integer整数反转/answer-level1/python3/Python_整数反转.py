### 解题思路
官方思路已经超过我的理解能力

分享一个鸡贼的方法：
1、int和str相互转化
2、利用string反转

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        y=int(str(x)[::-1]) if x>=0 else -int(str(x)[:0:-1])
        return y if -2**31<y<2**31-1 else 0
```
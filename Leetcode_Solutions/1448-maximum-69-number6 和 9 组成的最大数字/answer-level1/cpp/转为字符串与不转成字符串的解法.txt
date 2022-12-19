### 转成字符串的做法:

将第一位 6 替换为 9:

```python
class Solution:
    def maximum69Number (self, num: int) -> int:
        return int(str(num).replace('6', '9', 1))
```

### 不转为字符串的做法

python:

```python
class Solution:
    def maximum69Number (self, num: int) -> int:
        res = num
        n = num
        t = 1
        while num // t > 0:
            if n % 10 == 6:
                # 这里没有必要用 res = max(res, num + t * 3)
                # 因为如果走到这一步的话, num + t * 3 一定是大于 res 的
                res = num + t * 3
            t *= 10
            n //= 10

        return res
```

c++:

```
class Solution {
public:
    int maximum69Number (int num) {
        int res = num, n = num, t = 1;

        while (num / t) {
            if (n % 10 == 6) res = num + t * 3;
            t *= 10;
            n /= 10;
        }

        return res;
    }
};
```
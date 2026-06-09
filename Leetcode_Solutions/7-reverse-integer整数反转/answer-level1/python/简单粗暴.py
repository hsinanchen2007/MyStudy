## 思路：

### 思路 1：

字符串的反转，记录符号位。

### 思路 2：

与 10 的余数，是反转的最高位。

## 代码：

### 思路 1：

```Python []
class Solution:
    def reverse(self, x: int) -> int:
        flag = -1 if x < 0  else 1
        res = flag * int(str(abs(x))[::-1])
        return res if (-2**31)<=res<=(2**31-1) else 0
```

### 思路 2：

```Java []
class Solution {
    public int reverse(int x) {
        int res = 0;
        while( x != 0){
            int tail = x % 10;
            int newRes = res * 10 + tail;
            if ((newRes - tail)/10 != res)
                return 0;
            res = newRes;
            x /= 10;
        }
        return res;
    }
}
```


![image.png](https://pic.leetcode-cn.com/be0dadd7363e2ed8dad8adb924f74465a6d02c2f019949d0fdc21b7c37a487c2-image.png)

最快40ms，`+=`和`ans[:: -1]` 比 `ans = str(r) + ans` 写法会快不少，后者慢在反复新增地址，`divmod()`系统自带的商余计算比分开单独计算要快点。

```python []
class Solution:
    def convertToBase7(self, num: int) -> str:
        ans = '' if num != 0 else '0'
        sym = '-' if num < 0 else ''
        num = abs(num)
        while num:
            num, r = divmod(num, 7)
            ans += str(r)
        return sym + ans[:: -1]
```

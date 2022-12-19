```
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        a = version1.split('.')
        b = version2.split('.')
        length = len(a) if len(a) > len(b) else len(b)
        a.extend(['0'] * (length - len(a)))
        b.extend(['0'] * (length - len(b)))
        for i in range(length):
            if int(a[i]) != int(b[i]):
                return 1 if int(a[i]) > int(b[i]) else -1
        return 0

```

![截屏2020-02-02下午2.00.57.png](https://pic.leetcode-cn.com/7fc86b0b25ef36223ce5346f515ec55b05b90e09dd8016e2f4c68603578a82d8-%E6%88%AA%E5%B1%8F2020-02-02%E4%B8%8B%E5%8D%882.00.57.png)

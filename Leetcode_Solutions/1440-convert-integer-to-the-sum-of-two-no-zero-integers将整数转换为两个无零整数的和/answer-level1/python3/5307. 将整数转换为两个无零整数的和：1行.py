### 解题思路

next是个好东西

### 代码

暴力法：
```python []
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        return next([i, n - i] for i in range(n) if '0' not in str(i) + str(n - i))
```
随机法：
```python []
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        return next([i, n - i] for _ in itertools.count() if '0' not in str(i := random.randint(1, n - 1)) + str(n - i))
```

![image.png](https://pic.leetcode-cn.com/4c1e9fbf343c76c8572db280a8cead50eb31f46f236cb60c9f93e462958f27aa-image.png)

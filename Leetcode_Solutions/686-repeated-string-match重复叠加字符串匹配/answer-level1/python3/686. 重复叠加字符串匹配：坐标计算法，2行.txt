A叠加后的最大长度是$2*A.length+B.length$，所以按长度向上取整直接生成大最终字符串：

`s = A * math.ceil((len(A) * 2 + len(B)) / len(A))`

然后用`find()`查找`B`在`s`里的起始坐标，已知`B`的起始坐标`j`，`B`的长度`len(B)`，`A`的长度`len(A)`，自然就可以直接计算出`A`重复多少次可以覆盖`B`了。

计算公式也是向上取整：

`math.ceil((j + len(B)) / len(A))`

```python []
class Solution:
    def repeatedStringMatch(self, A: str, B: str) -> int:
        s = A * math.ceil((len(A) * 2 + len(B)) / len(A))
        j = s.find(B)
        return math.ceil((j + len(B)) / len(A)) if j != -1 else -1
```

简化成2行也是可以的。

```python []
class Solution:
    def repeatedStringMatch(self, A: str, B: str) -> int:
        j = (A * math.ceil((len(A) * 2 + len(B)) / len(A))).find(B)
        return math.ceil((j + len(B)) / len(A)) if j != -1 else -1
```

扩数据后212ms，也算在分布的左边了。

![image.png](https://pic.leetcode-cn.com/bd7969031d455e7a59acc2e9a995895affca7ee827107e92f1ab8223b445a79b-image.png)

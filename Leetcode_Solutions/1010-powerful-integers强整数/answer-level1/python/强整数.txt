#### 方法：暴力法

**思路**

如果 $x^i > \text{bound}$，那么 $x^i + y^j$ 也不可能小于等于 `bound`。  对于 $y^j$ 也是同样的道理。

因此，我们只需要对于所有的 $0 \leq i, j \leq \log_x(\text{bound}) < 18$ 生成一遍答案就行了。

我们可以用一个 `HashSet` 来存储所有不同的答案。

```java [AV4vVh9p-Java]
class Solution { 
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        Set<Integer> seen = new HashSet();
        for (int i = 0; i < 18 && Math.pow(x, i) <= bound; ++i)
            for (int j = 0; j < 18 && Math.pow(y, j) <= bound; ++j) {
                int v = (int) Math.pow(x, i) + (int) Math.pow(y, j);
                if (v <= bound)
                    seen.add(v);
            }

        return new ArrayList(seen);
    }
}
```
```python [AV4vVh9p-Python]
class Solution(object): 
    def powerfulIntegers(self, x, y, bound):
        ans = set()
        # 2**18 > bound
        for i in xrange(18):
            for j in xrange(18):
                v = x**i + y**j
                if v <= bound:
                    ans.add(v)
        return list(ans)
```


**复杂度分析**

* 时间复杂度：$O(\log^2{\text{bound}})$。

* 空间复杂度：$O(\log^2{\text{bound}})$。




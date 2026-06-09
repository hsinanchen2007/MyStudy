### 解题思路
感觉思路挺好想的
![2020-01-18 00-23-32屏幕截图.png](https://pic.leetcode-cn.com/a537690f56c7729fd31a1f72045210ffabbbe4f7c0a0b4d1ddc8735c39885ced-2020-01-18%2000-23-32%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)


### 代码

```python3
class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        import collections
        d = dict(collections.Counter(answers))
        res = 0
        for item in d:
            if item == 0:
                res += d[item]
            elif d[item] == item + 1:
                res += item+1
            elif d[item] < item+1:
                res += item + 1
            elif d[item] > item + 1:
                if d[item] % (item + 1) == 0:
                    res += (d[item]//(item+1)) * (item + 1)
                else:
                    res += (d[item] // (item + 1)+1) * (item + 1)
        return res
```
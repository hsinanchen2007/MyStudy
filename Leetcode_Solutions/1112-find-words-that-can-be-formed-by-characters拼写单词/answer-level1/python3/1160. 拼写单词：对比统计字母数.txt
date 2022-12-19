就是直接数字母数量再比对数量多少，用函数封装有利于跳出循环。

```python []
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        c_ct = collections.Counter(chars)
        def f(w):
            w_ct = collections.Counter(w)
            for c in w:
                if w_ct[c] > c_ct[c]:
                    return False
            return True
        return sum(map(len, filter(f, words))) #过滤后长度求和
```

提交的人数还比较少，260ms仅供参考。

![image.png](https://pic.leetcode-cn.com/cb5409a778f689f7babf1a8011cca2309a915ff776bf178eab5bf63dcefa64a7-image.png)

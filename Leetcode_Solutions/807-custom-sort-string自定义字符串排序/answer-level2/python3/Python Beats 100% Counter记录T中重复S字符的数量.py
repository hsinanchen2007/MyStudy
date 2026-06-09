![截屏2020-02-1012.10.07.png](https://pic.leetcode-cn.com/4812533500c514997fb8b74aaff3985206807fd7724ff541c4234cd312ef510f-%E6%88%AA%E5%B1%8F2020-02-1012.10.07.png)

从题意我们可以知道`T`中的字符一种是S中出现的，一种是`S`中没出现的。对于出现的，肯定是和`S`相同的顺序，不需要再重新排序或者插入，只是不一定重复多少次。而对于没出现的，在哪都可以，为了简单起见就放在`ans`串的最后。

那么我们就可以先预处理，统计`T`中字符每个都出现了多少次。对于在`S`中出现的就输出对应字符的次数，对于`S`中没出现的，就在最后输出。

```python
from collections import Counter

class Solution:
    def customSortString(self, S: str, T: str) -> str:
        n = len(T)
        cnt = Counter(T)
        que = []
        for ch in S:
            que.append(ch*cnt[ch])
        for ch in T:
            if ch not in S:
                que.append(ch)
        ans = ''.join(que)
        return ans
                
```

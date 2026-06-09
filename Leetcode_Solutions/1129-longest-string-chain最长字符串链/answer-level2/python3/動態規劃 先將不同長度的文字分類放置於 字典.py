### 解题思路
動態規劃 先將不同長度的文字分類放置於 字典
再將 N長度的文字與 N-1長度的文字 進行比較
如果發生符合條件的 情況 就將 組成詞鍊的長度加一
最後取出最長的數值

### 代码

```python3
class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        content_w = collections.defaultdict(list)
        content_v = collections.defaultdict(list)

        short_w = float('inf')
        long_w = 0
        for w in words:
            short_w = min(short_w, len(w))
            long_w = max(long_w, len(w))
            content_w[len(w)].append(w)
            content_v[len(w)].append(1)

        res = 1
        for length in range(short_w+1, long_w + 1):
            for idx_L, lg_w in enumerate(content_w[length]):
                for idx_S, sh_w in enumerate(content_w[length-1]):
                    lg_w_copy = sorted(lg_w)
                    for sw in sh_w:
                        if sw in lg_w_copy:
                            lg_w_copy.pop(lg_w_copy.index(sw))
                    if len(lg_w_copy) == 1:
                        content_v[length][idx_L] = content_v[length-1][idx_S] + 1
                        res = max(res, content_v[length][idx_L])
        return res














```
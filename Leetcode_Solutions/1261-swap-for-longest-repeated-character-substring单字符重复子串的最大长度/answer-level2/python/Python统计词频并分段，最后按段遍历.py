```python
class Solution:
    def maxRepOpt1(self, text: str) -> int:
        counts, lens, _len = {}, [], 0
        for i, alpha in enumerate(text[:-1]):  # 统计字频以及划分连续段
            counts[alpha] = counts.get(alpha, 0)+1
            _len += 1
            if text[i+1] != alpha:
                lens.append((alpha, _len))
                _len = 0
        counts[text[-1]] = counts.get(text[-1], 0)+1
        _len += 1
        lens.append((text[-1], _len))

        _max = 0
        for i, (alpha, _len) in enumerate(lens):
            if _len >= _max:  # 如果该段长度>=现最大值
                if _len < counts[alpha]:  # 还可以替换加一位
                    _max = _len+1
                elif _len == counts[alpha]:  # 不可替换了
                    _max = _len
            elif _len == 1 and 0 < i < len(lens)-1 and lens[i-1][0] == lens[i+1][0]:  # 如果该段就单字符且左右段相同
                _alpha, len_l, len_r = lens[i-1][0], lens[i-1][1], lens[i+1][1]
                if counts[_alpha] > len_l+len_r >= _max:  # 替换该段可将左右连起来获得更大值
                    _max = len_l+len_r+1
                elif counts[_alpha] == len_l+len_r and len_l+len_r > _max:  # 不可替换了
                    _max = len_l+len_r
        return _max
```
            
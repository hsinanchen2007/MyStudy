### 解题思路
此处撰写解题思路
先用Counter 统计出每个数出现的频次
然后将所有的频次进行求最大公约数
如果最大公约数大于等于2的话则符合要求
### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        card_map = Counter(deck)
        value_list = list(card_map.values())
        def gcd(a,b):
            return a if not b else gcd(b,a%b)
        def gcd_list(card:List[int]):
            if len(card) == 0:
                return  0
            if len(card) == 1:
                return card[0]
            res = card[0]
            for item in card[1:]:
                res = gcd(res,item)
            return res
        return gcd_list(value_list) >=2
```
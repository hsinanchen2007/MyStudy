### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        count=collections.Counter(deck)
        x=min(count[i] for i in count)
        //主要目的是因为方便计算，其他不找这个min也是可以的
        for i in count:
            x=math.gcd(x,count[i])
        //求得所有次数之间的最大公因数
        if x<2:
            return False
        return True

```
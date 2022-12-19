### 解题思路
由题意得，deck中各数字的数目只能是某个大于1的整数的倍数，因此，只要所有数目存在一个公因数，即两两间最大公因数不是1，则返回True，否则返回False。具体做法如下：
1、记录每个数出现的次数
2、计算相邻两个数目最大公因数是否为1。

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:

        sets = set(deck)
        L = [deck.count(i) for i in sets]
        for i in range(len(L)-1):
            if math.gcd(L[i],L[i+1]) == 1:
                return False
        return len(deck) > 1 and True
                
```
4的倍数为一个必败态，非4的倍数为必胜态，因为当面对非4的倍数时你总可以取1,2或3个石子，让对方始终面临4的倍数，最后一轮为4，对方拿走一部分后再把剩下的全部取出即可获胜。
![8(XKG\]JL80XRLH~HM\]B(B{V.png](https://pic.leetcode-cn.com/b0f4c48ef9b8a6f2eb962dce5e0998548c020a8ddc93f6f043961940572c8db5-8\(XKG%5DJL80XRLH~HM%5DB\(B%7BV.png)


```
class Solution:
    def canWinNim(self, n: int) -> bool:
        if n%4==0:
            return False
        else:
            return True
```

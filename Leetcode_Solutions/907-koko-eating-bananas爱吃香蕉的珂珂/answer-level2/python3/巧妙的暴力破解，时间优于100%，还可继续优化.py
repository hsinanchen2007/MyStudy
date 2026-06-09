### 优于100%图片
![屏幕快照 2020-01-14 下午8.43.22.png](https://pic.leetcode-cn.com/5552b6608ba05d69b253f0f242050e216fba7863374854d181fc835914c37483-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-01-14%20%E4%B8%8B%E5%8D%888.43.22.png)

### 解题思路
此处撰写解题思路
巧妙之处在于：找寻上下限，然后在之间找最优解。
上限=香蕉总数/次数
下限=最大香蕉堆的香蕉数/(次数/香蕉堆数)
我是举最好，最差情况来验证的。

然后上下限间找最优解即可，变为一个查找问题，暴力可优化为二分查找。

### 代码

```python3
import math
class Solution:
    def minEatingSpeed(self, piles: List[int], H: int) -> int:
        size = len(piles)
        begin = int(math.ceil(sum(piles)/H))
        end = int(math.ceil(max(piles)/(H/size)))
        #暴力
        for i in range(begin, end+1):
            allNum = 0
            for item in piles:
                allNum += int(math.ceil(item/i))
            if(allNum <= H):
                return i
        return 0
```
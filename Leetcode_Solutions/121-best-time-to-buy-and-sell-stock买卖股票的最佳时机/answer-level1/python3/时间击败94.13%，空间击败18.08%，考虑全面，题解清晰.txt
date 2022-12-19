### 解题思路
使用两次循环的暴力法时，大家会发现内存超出了，所以需要一次循环，官方解释的第二种方法考虑的不全面，类似[3,21,1,5,9]的数组没考虑到

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_p = 0
        if prices != []:  #数组为空时，最大利润为零
            minn = prices[0]
            for i in range(len(prices)):
                if prices[i] < minn:  #如果遇到值小于之前保存的最小值时，不要立即用新的最小值代替，而是需要判断之前的最大利润是否足够大，防止[3,21,1,5,9]数组找不到真正的最大利润
                    if prices[i-1] - minn > max_p:
                        max_p = prices[i-1] - minn
                    minn = prices[i]  #判断后把新的最小值保存起来  
                elif prices[i] > minn and prices[i] - minn > max_p:
                    max_p = prices[i] - minn
        return max_p



```
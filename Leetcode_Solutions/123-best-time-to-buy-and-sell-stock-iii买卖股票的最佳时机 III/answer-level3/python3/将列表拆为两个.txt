### 解题思路
# 想法1、将列表拆为两个，然后分别应用买卖股票的最佳时机I场景，求和，最后取和的最大值。

```
def maxProfit(self, prices: List[int]) -> int:
    if not prices or len(prices)==1:
        return 0
    if len(prices)==2:
        return max(0, prices[1]-prices[0])
    ans = 0
    n = len(prices)
    for idx in range(1, n-1):
        min_left, max_left = prices[0], 0
        for i in range(1, idx+1):
            if prices[i]<min_left:
                min_left = prices[i]
            else:
                max_left = max(max_left, prices[i]-min_left)
        min_right, max_right = prices[idx], 0
        for j in range(idx, n):
            if prices[j]<min_right:
                min_right = prices[j]
            else:
                max_right = max(max_right, prices[j]-min_right)
        ans = max(ans, max_right+max_left)
    return ans
```
最后两重循环，但是超出了时间限制。

# 想法2、优化两重循环，用空间换时间。
left数组从左到右求极小值来确定股票的最大收益；
right数组从右到左求极大值来确定股票的最大收益，right数组倒置即和left数组顺序一致；
两个数组对应元素和的最大值即为股票整体的最大收益。

```
def maxProfit(self, prices: List[int]) -> int:
    if not prices or len(prices)==1:
        return 0
    if len(prices)==2:
        return max(0, prices[1]-prices[0])
    ans = 0
    n = len(prices)
    left, right = [0], [0]
    min_price, max_price = prices[0], prices[n-1]
    max_left = 0
    for i in range(1, n):
        if prices[i]<min_price:
            min_price = prices[i]
            left.append(left[-1])
        else:
            max_left = max(max_left, prices[i]-min_price)
            left.append(max_left)
    max_right = 0
    for j in range(n-2, -1, -1):
        if prices[j]>max_price:
            max_price = prices[j]
            right.append(right[-1])
        else:
            max_right = max(max_right, max_price-prices[j])
            right.append(max_right)
    right = right[::-1]
    for idx in range(1, n-1):
        ans = max(ans, right[idx]+left[idx])
    return ans
```
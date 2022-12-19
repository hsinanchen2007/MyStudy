一次遍历，原先price_in、price_out单纯是数字，后考虑到prices = [2，4, 1]这种情况，将价格变成一对一对的列表，遍历列表，刷新profit

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
       if not prices:
            return 0

        price_in, price_out = [prices[0]], [prices[0]]
        for i in range(len(prices)):
            temp = prices[i]
            if temp < price_in[-1]:
                price_in[-1] = temp
                price_out[-1] = temp
            elif temp > price_out[-1]:
                price_out[-1] = temp
                price_in.append(price_in[-1])
                price_out.append(price_in[-1])
            else:
                continue

        profit = 0
        for i in range(len(price_in) - 1):
            cur = price_out[i] - price_in[i]
            if cur > profit:
                profit = cur
        return profit
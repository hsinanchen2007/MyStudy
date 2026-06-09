class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        <!-- 先判断 只有一个或者0个元素就直接返回 这一步不能省 不然会耽误后面 -->
        if len(prices)<2 :
            return 0   
        <!-- 这个left是全局重点 有了它只需要一层for -->
        left_lowest=prices[0]
        max=0
        for i in range(1,len(prices)):
            if prices[i]<left_lowest:
                left_lowest=prices[i]
            <!-- 这个elif必须加 max本身就需要被判断 -->
            elif (prices[i]-left_lowest)>max:
                max=prices[i]-left_lowest
        return max
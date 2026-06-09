和1262非常的类似，只需要在判断最大和的时候改成判断最大积，并且特判一下和为0，打比赛的时候死在这个上面五次就很气。

class Solution:
    def largestMultipleOfThree(self, digits: List[int]) -> str:
        
        dp = [0,-1,-1]
        digits.sort(reverse=True)
        for n in digits:
            n = int(n)
            dp = [max(dp[i],dp[(i+n)%3]*10+n) for i in range(3)]
        
        if sum(digits)==0:
            return '0'
        else:
            return str(dp[0]) if dp[0]>0 else ''
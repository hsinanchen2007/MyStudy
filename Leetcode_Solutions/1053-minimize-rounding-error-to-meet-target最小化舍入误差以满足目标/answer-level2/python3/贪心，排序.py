```
class Solution:
    def minimizeError(self, prices: List[str], target: int) -> str:
        prices=[float(i) for i in prices]
        min_sum=sum(int(i) for i in prices)
        max_sum=min_sum+sum(1 for i in prices if i-int(i))

        if target>max_sum or target<min_sum:
            return "-1"

        diff=target-min_sum
        prices.sort(key=lambda x:x-int(x),reverse=True)
        res=0.0

        for i in range(diff):
            res+=int(prices[i])+1-prices[i]
        for i in range(diff,len(prices)):
            res+=prices[i]-int(prices[i])

        return format(res,".3f")
```

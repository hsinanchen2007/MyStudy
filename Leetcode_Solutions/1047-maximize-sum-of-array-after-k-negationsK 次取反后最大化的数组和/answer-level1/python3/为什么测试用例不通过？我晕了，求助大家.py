![1583166197(1).jpg](https://pic.leetcode-cn.com/1011d385b6036aa31f536b3dca168adf4d6a1eab1e861f7cc829de933d0f189d-1583166197\(1\).jpg)
我用的是正负数分组的笨办法，但是想不通这个测试用例怎么没通过，我晕头
```
class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        negativenums=[]
        positivenums=[]
        for num in A:
            if num>=0:
                positivenums.append(num)
            else:
                negativenums.append(num)
        n=len(negativenums)
        tmp=sorted(negativenums,reverse=True)
        if n>=K:
            return sum(positivenums)-sum(tmp[n-K:])
        else:
            possiblemax=sum(positivenums)-sum(negativenums)
            if (K-n)%2==0:
                return possiblemax
            else:
                if n==0:
                    return possiblemax-min(positivenums)*2
                else:
                    return positivenums+tmp[-1]
```

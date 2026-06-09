```
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        ans=[]
        for i in range(target//2,1,-1):
            # i是项数. i个连续正数的首项与末项和为2*target//i。联立方程得到a_1和a_n的表达式。
            if (2*target)%i==0 and (2*target//i+i)%2 and 2*target//i>=i:
                ans.append(list(range((2*target//i-i+1)//2,(2*target//i+i+1)//2)))

        return ans
```
额外需要小心的是正整数的要求（第三个判断条件），以及整除的要求（第二个判断条件）。

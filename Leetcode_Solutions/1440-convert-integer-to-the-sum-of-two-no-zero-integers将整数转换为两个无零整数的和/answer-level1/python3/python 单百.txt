执行用时 :
32 ms
, 在所有 Python3 提交中击败了
71.25%
的用户
内存消耗 :
13 MB
, 在所有 Python3 提交中击败了
100.00%
的用户
代码如下
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        ans=[]
        for i in range(1,n):
            a=str(i)
            b=str(n-i)
            if '0' not in a and '0' not in b:
                ans.append(i)
                ans.append(n-i)
                break
        return ans
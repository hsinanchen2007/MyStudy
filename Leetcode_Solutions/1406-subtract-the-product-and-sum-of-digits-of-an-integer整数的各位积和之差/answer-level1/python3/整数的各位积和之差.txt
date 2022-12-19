解题思路
hhh，第一次打败了100%

代码

python3
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        str_n=str(n)
        a=1
        b=0
        for i in str_n:
            a*=int(i)
            b+=int(i)
        return a-b
        
            

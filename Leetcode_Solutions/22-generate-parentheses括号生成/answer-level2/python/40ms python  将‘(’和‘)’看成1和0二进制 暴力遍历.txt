### 解题思路
将‘(’和‘)’看成1和0，结果可看成一个二进制数，由于首尾确定了，中间的可能情况有2^(n-1)。
由于对称性可考虑左半部分，循环遍历出符合要求的左半部分，右半翻转即可。
写的比较杂乱，应该有优化的空间。

### 代码

```python3
def toLPar(s):
    p='('
    for k in s:
        if k=='0':
            p+=')'
        else:
            p+='('
    return p
def toRPar(s):
    p=')'
    for k in s:
        if k=='0':
            p+='('
        else:
            p+=')'
    return p[::-1]
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n>1:
            ans=[]
            left,right={},{}
            for i in range(0,2**(n-1)):
                mm=1#待匹配的左括号数量，首位已确定（，故为1
                s=str.zfill(bin(i)[2:],n-1)#转成二进制对应的字符串并补足位数
                for k in s:             
                    if k=='0':
                        mm-=1
                        if mm<0:#右括号的数量不能多于左括号
                            break
                    else:
                        mm+=1 
                if mm in left:
                    left[mm].append(toLPar(s))
                    right[mm].append(toRPar(s))
                elif mm>=0:
                    left[mm]=[toLPar(s)]
                    right[mm]=[toRPar(s)]
            for i in range(n%2,n+1,2):
                ans.extend([p+q for p in left[i] for q in right[i]])
            return ans
        elif n==1:
            return ['()']
        else:
            return []




```
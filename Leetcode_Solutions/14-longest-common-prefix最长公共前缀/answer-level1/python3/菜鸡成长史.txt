### 解题思路
此处撰写解题思路

### 代码

```python3
from typing import List
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        n=len(strs)
        if n==0:
            return ''
        elif n==1:
            return strs[0]
        else:
            l=[]
            for aa in range(n):
                l.append(len(strs[aa]))
            h=min(l)   #最少字符数的单词的字符数
            samestr=''
            bbb=0
            for m in range(h):        #单词中的第几个字符
                for i in range(1,n):  #字符串中的第几个单词
                    q=strs[i][m]
                    p=strs[i-1][m]
                    if q!=p:
                        if bbb == 0:
                            return ''
                            # break
                        else:
                            # return samestr
                            # break
                            # samestr=samestr+strs[1][m]
                            return samestr
                    elif i==n-1:
                        samestr = samestr + strs[1][m]
                bbb = bbb + 1

                    # else:
                    #     break
            if bbb==0:
                return ''
                # break
            else:
                # return samestr
                # break
                # samestr=samestr+strs[1][m]
                return samestr

# if __name__=='__main__':
#     lll=Solution()
#     strs=["aca","cba"]
#     print(lll.longestCommonPrefix(strs))

```
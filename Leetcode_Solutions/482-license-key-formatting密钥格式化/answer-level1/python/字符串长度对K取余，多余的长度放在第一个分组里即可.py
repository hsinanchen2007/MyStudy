### 解题思路
思路还是比较明晰的
1.用python库函数处理字符串，去掉’-‘并且转大写
2.字符串长度对K取余，第一个分组先放余数长度个字符
3.遍历字符串，每K个字符放在结果串中，加上’-‘
4.最后去掉末尾多余的’-‘

### 代码

```python3
class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        S=S.replace('-','').upper()
        res=''
        first=len(S)%K
        if first!=0:
        res+=S[0:first]+'-'
        for i in range(first,len(S),K):
            res+=S[i:i+K]+'-'
        return res.strip('-')

```
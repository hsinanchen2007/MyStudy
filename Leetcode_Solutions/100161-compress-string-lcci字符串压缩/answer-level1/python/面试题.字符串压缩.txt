### 解题思路
- 设字母连续出现次数为n,则压缩效益为n-2（2是压缩长度）
- 维护flag存储压缩效益，如果压缩效益大于0则输出压缩结果，反之输出字符;
- 维护cur记录待计算重复次数的字符，维护count记录字符重复次数，维护字符串res记录压缩结果
- 遍历字符串，count记录字符重复次数直到不同字符出现时，更新cur,res,更新flag。


### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        S = S+'0'
        flag = 0
        count = 1
        cur = S[0]
        res = ''
        for index, s in enumerate(S):
            if index==0: continue
            if cur==s:
                count = count +1
            if cur!=s or s=='0':
                res = res+S[index-1]+str(count)
                flag = flag + count-2 
                count = 1
                cur = s
        return S[0:-1] if flag<=0 else res


```
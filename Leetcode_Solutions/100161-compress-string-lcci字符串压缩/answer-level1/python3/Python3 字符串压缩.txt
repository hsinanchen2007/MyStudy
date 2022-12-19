### 解题思路
第一次解题，并且以前没有学习过算法和数据结构整理下别人的思路以及自己的理解~，！

函数定义： 输入字符串，得到压缩后的字符串
主要逻辑：通过下标遍历字符串，如果当前字符串与下一个字符串相同，则计数器+1，依次遍历，当结果不一致时，则将相同的字符串与计数器拼接，直到循环结束，判断原字符串和转换后的字符串长度，如果转换后长度大于等于转换前就返回转换前的，否则返回转换后的字符串

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        S +="-"
        cut,n,encode = 1,len(S),""
        for i in range(1,n):
            if S[i] == S[i-1]:
                cut +=1
            else:
                encode += S[i-1]+str(cut)
                cut = 1
        return S[:-1] if len(encode) >= n-1 else encode


            


```
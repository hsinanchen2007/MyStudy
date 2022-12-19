### 解题思路
如果字符串长度小于等于1直接返回
通过while循环处理 str[:len-2] ，str[len-1]单独处理
1. 其中一个快指针j用来比较连续的两个字符串是否相灯
2. 另外一个慢指针i指向连续相同字符串段的首位
3. 定义一个空字符串
4. 比较j和j+1指向的值，当指针j和j+1指向值不同的时候 指针 i=j+1(指向新的连续字符串段的首位置)，空字符进行拼接
5. 每次比较完后j=j+1
6. 判断j<len(s)-1是否成立，成立从新进行步骤4-6
7. 最后处理末尾字符串（最后两个字符相等，指针i指向最后一段连续字符串首位置。最后两个字符不相等i和j都指向字符串末位置，res+=res[i]+str(j-i+1)都可以满足）
8. 判断长度 进行返回

### 代码

```python
class Solution(object):
    def compressString(self, S):
        """
        :type S: str
        :rtype: str
        """
        
        i = 0
        j = 0
        res = ''
        len_s = len(S)
        if len_s<=1:
            return S
        while j<len_s-1:
            if S[j]!=S[j+1]:
                res+=S[i]+str(j-i+1)
                i=j+1
            j+=1
        
        res+=S[i]+str(j-i+1)
        
        if len(res)>=len(S):
            return S
        return res
```
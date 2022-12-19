### 解题思路
首先排除了空列表空字符串的情况，按照最小字符串的长度确定了遍历深度，依次对各字符串进行遍历，prefix是公共比较对象，当所有字符串比较通过后交给prefix2，一旦比较失败返回prefix2

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix=""                          #公共比较对象
        prefix2=""                         #公共前缀  
        if len(strs) == 0:                   #空列表返回""
            return ""
        min_len = min ( len(item) for item in strs)  #计算最小字符串长度
        if min_len != 0:                              #当没有空字符串的情况下   
            for i in  range(min_len):                 #以最小字符串长度作为遍历深度
                prefix += strs[0][i]                  #对第一个字符串取公共比较对象
                for j in range(len(strs)):             #对所有字符串遍历
                    if prefix != strs[j][:len(prefix)]:  #当前字符串前缀与公共比较对象比较
                        return prefix2                   #比较失败返回   
                    else:                               #比较成功继续
                        pass
                prefix2 = prefix                         #所有都比较成功公共字符串确定为目标前缀
            return prefix2                              #完成深度遍历后返回
        return ""                                     #当存在空字符串的情况返回结果


```
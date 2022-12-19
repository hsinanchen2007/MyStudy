### 解题思路
【今天是暴力求解】
words按单词长度排序，单词长度由长到短遍历，如果目标字符串中可完全读取该单词，舍弃该单词
完全读取：字符串中存在该单词子串，并以“#”结尾

函数
+ list.sort(cmp=None, key=None, reverse=False)
    cmp - 可选参数，使用该参数的方法进行排序
    key - 排序依据，只有一个参数
    reverse - 排序规则，默认False（升序）
+ str.find(str1, begin, end)
    str1 - 子字符串
    begin: end - 查找范围
    若str1在str中，返回str1的索引；若不在，返回-1

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words.sort(key = lambda x: len(x))          #按单词长度排序
        ans = ''                                    #目标字符串
        for i in range(len(words)-1, -1, -1):       #按单词长度从长到短遍历（逆序循环）
            tmp = ans.find(words[i])                #单词是否在目标字符串中，若存在，返回索引
            if tmp == -1:                           #单词不在目标字符串中，添加进去
                ans += words[i] + '#'
            else:                                   #单词在目标字符串中，判断能否完全读取
                x = ans[tmp:].index('#')            #获取单词后第一个“#”索引
                if ans[tmp:tmp+x] != words[i]:      #判断是否能够完全读取，若不能，添加单词
                    ans += words[i] + '#'
        return len(ans)                             #返回目标字符串长度
```
### 解题思路
(1)文字思路

先考虑长单词，再考虑短单词是否镶嵌并同时处于长单词结尾处。因此，
**第一步**，将words列表按照表项长度逆序排列，可借用sort()方法，嵌入两个参数，分别为不知名函数lambda用以表示按照表项长度排序，另一个参数reverse=True，表示为逆序
**第二步**，建立目标空字符串ans，遍历已按表项长度逆序排列的words列表，
如果目标字符串中不能读取该单词，则find()方法返回-1，则在ans中新增该单词，并以#结尾；
如果目标字符串中能够完全读取该单词，find()方法返回索引下标，此时应判断这单词是否以#结尾，那么可找出紧接着#的下标，判断两者之间的字符串是否等于该单词，如果是，则跳过；否则，ans需新增该单词并以#结尾
**第三步**，跳出循环，返回len(ans)即可

(2)按表项长度逆序排序的方法

list.sort(key, reverse)
此时以key=lambda和reverse=True为参数，表示按照lambda函数（指代未命名的函数），逆序排列列表

未命名函数lambda纯粹是为了方便，参考链接为：

https://blog.csdn.net/huangmengfeng/article/details/79775599?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522158537628219724848302963%2522%252C%2522scm%2522%253A%252220140713.130056874..%2522%257D&request_id=158537628219724848302963&biz_id=0&utm_source=distribute.pc_search_result.none-task

(3)find()和index()区别

find()方法，检查字符串 返回下标；错误返回-1
index()方法，简单处理字符串的话与find()函数的用法相同，只是在检查到不存在要索引的字符串的时候会报一个异常。

**(4)必看贴子**（发现了个与此题契合度很高的知识贴）

https://blog.csdn.net/weixin_43790276/article/details/90247230?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522158538118919725222406456%2522%252C%2522scm%2522%253A%252220140713.130056874..%2522%257D&request_id=158538118919725222406456&biz_id=0&utm_source=distribute.pc_search_result.none-task

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words.sort(key = lambda x: len(x), reverse=True)
        ans = ''
        for i in range(len(words)):
            tmp = ans.find(words[i])
            if tmp == -1:
                ans += words[i] + '#'
            else:
                x = ans[tmp:].index('#')
                if words[i] != ans[tmp:tmp+x]:
                    ans += words[i] + '#'
        return len(ans)


```
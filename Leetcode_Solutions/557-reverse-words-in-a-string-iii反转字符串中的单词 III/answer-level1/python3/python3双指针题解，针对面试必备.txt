python自带的字符串函数解这种题绝对是`return ' '.join(map(lambda x:x[::-1],s.split()))`之类的一刀流，但面试时候这么写没营养的代码不行的。参考[python3的纯粹双指针解法，简洁易懂，不用任何内置字符串函数！](https://leetcode-cn.com/problems/reverse-words-in-a-string/solution/python3de-chun-cui-shuang-zhi-zhen-jie-fa-jian-ji-/)，写出如下双指针方法代码：
```
class Solution:
    def reverseWords(self, s: str) -> str:
        j = 0 ## 慢指针
        for i in range(len(s)):
            if s[i]==' ': ## 慢指针触发
                s = s[:j]+s[j:i][::-1]+s[i:] #业务代码
                j = i+1
            elif i ==len(s)-1: ## 业务代码
                s = s[:j]+s[j:][::-1]
        return s  
```
时间复杂度O(n)
空间复杂度O(1)
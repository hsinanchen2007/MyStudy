```
class Solution:
    def reverseWords(self, s: str) -> str:
        # 字符串切分为数组
        terms = s.split(' ')
        for i in range(len(terms)):
            # 字符串反转
            terms[i] = terms[i][::-1]
        # 将数组拼接为字符串
        return ' '.join(terms)
            
        
```

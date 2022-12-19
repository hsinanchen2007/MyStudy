### 回溯法解决
![image.png](https://pic.leetcode-cn.com/884fe2cda3e3bff9a801c753b792dca2942e4103d7c31eec4deba4303a92e82b-image.png)

- 参照剑指offer官方题解,分成两步:
1. 第一步,求所有可能出现在第一个位置的字符,即把第一个字符和后面所有的字符进行交换
2. 第二步,固定住第一个字符,求后面字符的全排列.这时候我们仍把后面的字符分成两部分: 后面字符的第一个字符以及这个字符后面的所有字符.
然后把第一个字符逐一和它后面的字符交换.

- 算法最后的结果可能会有重复的情况出现,我们使用`python`自带的`set()`函数来去重
- 

### 代码

```python
class Solution(object):
    def permutation(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        result = []
        if not s:
            return []
        s = list(s)
        temp = [] 
        self.stringSort(s, temp, result)
        return list(set(result))
    
    def stringSort(self, s, temp, result):
        if len(s) == 1:
            temp.append(s[0])
            result.append(''.join(temp))
            temp.pop()
            return 
        for i in range(0,len(s)):
            if i!= 0 and s[i] == s[0]:
                continue
            s[0],s[i] = s[i],s[0]
            temp.append(s[0])
            self.stringSort(s[1:], temp, result)
            temp.pop()
            s[i], s[0], = s[0], s[i]
            





```
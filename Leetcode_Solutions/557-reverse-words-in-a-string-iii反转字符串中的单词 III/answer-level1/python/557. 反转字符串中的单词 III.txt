**第二种效率高些，不同在意字符串和list的翻转**

1.
- - str.split() 拆分
- list2.reverse() 反转
- 拼接 rules.join(list)

```
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        List = s.split()
        L = []
        for i in List:
            list2 = list(i)
            list2.reverse()
            L.append(''.join(list2))
            # L.append(i[::-1])
            
        return ' '.join(L)

print Solution().reverseWords("Let's take LeetCode contest")

```

2. 处理唯一不同的是 字符串翻转
L.append(i[::-1])

```
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        List = s.split()
        L = []
        for i in List:
            L.append(i[::-1])
            
        return ' '.join(L)

print Solution().reverseWords("Let's take LeetCode contest")

```

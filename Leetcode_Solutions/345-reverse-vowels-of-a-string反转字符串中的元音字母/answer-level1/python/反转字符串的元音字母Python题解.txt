### 解题思路
双指针遍历字符串
注意点：
1.元音字母包括大小写
2.python的字符串不可修改需要改成list
3.返回值是字符串，需要用string类型中的join方法
### 代码

```python
class Solution(object):
    def reverseVowels(self, s):
        s = list(s)
        vowels = ['a', 'e', 'o', 'i', 'u', 'A', 'E', 'O', 'I', 'U']
        i = 0
        j = len(s) - 1
        while(i <= j):
            if s[i] in vowels:
                while(s[j] not in vowels) and (i <= j):
                    //查找元音字母，查到停止
                    j -= 1
                temp = s[i]
                s[i] = s[j]
                s[j] = temp
                j -= 1
            i += 1
        return ''.join(s)
```
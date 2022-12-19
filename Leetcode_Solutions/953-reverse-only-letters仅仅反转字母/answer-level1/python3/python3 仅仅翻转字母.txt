### 解题思路
思路：先说一下字母的ASCII码 A~Z=65~90 a~z=97~122
相当于在字符串的首位各立一根筷子，然后
第一步，判断首处筷子的值的是否为字母，如果不是字母，首处筷子就向前移一步，如果是字母，进入第二步。
第二步，判断尾处的筷子的值是否为字母，如果不是字母， 尾处的筷子就向后移一步，如果是字母，进入第三步。
第三部，首处筷子的字母和尾处字母的筷子交换位置。
这样一直循环，直到首处筷子的索引大于了尾处筷子的索引，说明这个字符串就交换完成了。



### 代码

```python3
class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        i = 0     #首处的筷子
        j = len(S)-1  #尾处的筷子
        SS = list(S)   #把字符串放进列表方便取值
        while i < j:   
            if not SS[i].isalpha():  #判断首处筷子的值是否为字母
                i +=1               #如果不是 首处筷子向前移一步
            elif not SS[j].isalpha():  #判断尾处筷子的值是否为字母
                j -=1              #如果不是，尾处筷子向后移一步
            else:                 #如果首处和尾处的筷子都是字母
                SS[i],SS[j] = SS[j], SS[i]  #那就交换首尾筷子的值
                i +=1   
                j -=1
        return ''.join(SS)
```

#法二   其实和第一种解法是一个意思
class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        i = 0
        j = len(S)-1
        SS = list(S)
        while i <j:
            if ord(SS[i])<65 or 90<ord(SS[i])<97 or ord(SS[i])>122:
                i +=1
            elif ord(SS[j])<65 or 90<ord(SS[j])<97 or ord(SS[j])>122:
                j -= 1
            else:
                SS[i],SS[j] = SS[j], SS[i]
                i +=1
                j -=1
        return ''.join(SS)
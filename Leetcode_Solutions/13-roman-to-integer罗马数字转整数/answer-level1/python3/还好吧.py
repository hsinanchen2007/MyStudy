### 解题思路
可以把每个字母代表的值和字母本身放在一个字典中，然后判断在字符串s中后者是不是比前面大，如果大于，就把当前字母值变为
负值，因为在当跳到下一位时，会加上下一位值，而这两个数就相当与是后面一位减去前面一位，所以直接把前面一位负就行，或者是判断位置在后面一位时，可以把后面的减去前面的两倍，原理和上面一样，就是位置不一样。
### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        num=0
        dir={"I": 1 , "V": 5 , "X": 10 , "L": 50,"C":100,"D":500,"M":1000}
        for i in range(len(s)):
            if i<len(s)-1 and dir[s[i+1]]>dir[s[i]]:

                num -=dir[s[i]]
            else:
                num +=dir[s[i]]
        return num

```
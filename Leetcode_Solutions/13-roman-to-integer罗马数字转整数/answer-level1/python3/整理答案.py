解法一：借鉴Knife大佬的答案：
思想：
1. 将两个字符组合的所有情况和单个字符的所有情况都存到字典中
2. 然后从头遍历给定的字符序列，优先判断目前指向的两个字符是不是合法的二字母组合
3. 如果是，也就是在字典中能找到匹配的值，那就将其加到num上；
4. 如果不是，就直接找到当前这个字母对应什么值，加上就可以了
5. eg. XCVI：下标移到0时，指针指‘X’，在字典中没有两字母‘_X’的匹配结果，所以num直接加10，但移到下个位置1时，指针指‘C’，在字典中有'XC'的匹配结果, 所以num加上对应的值80。后面依次类推。
注：因为两字母的情况（XC）将前一个X多加了一遍，所以相当于多加了10，所以字典中XC的对应value值应该减去左边字母的对应值，也就是90-10=80. 如果不这样设定，直接设XC的value=90也可以，那就应该先看s[i:i+2]是否是二字母情况，如果是，那就直接后移两位，跳过右边字母的判断。
```
class Solution:
    def romanToInt(self, s: str) -> int:
        d = {'I':1, 'IV':3, 'V':5, 'IX':8, 'X':10, 'XL':30, 'L':50, 'XC':80, 'C':100, 'CD':300, 'D':500, 'CM':800, 'M':1000}
        num = 0
        for i,x in enumerate(s):
            twin = s[i-1: i+1]
            if d.get(twin)!= None:
                num += d.get(twin)
            else:
                num += d.get(x)
        return num
```



解法二：借鉴junex233的思路，转换的实质是：若出现前一个字母比后一个小的二字母组合，则num要减去前一个的值，前>后，则num是加上前一个的值，这样从i=0开始依次检查s[i] s[i+1]的组合，根据相应的情况加上或减去s[i]，最后一个元素单独处理，直接加到num上即可（因为最后一个后面不可能有比它大的字母出现了）。
```
class Solution:
    def romanToInt(self, s: str) -> int:
        d = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        num = 0
        for i,x in enumerate(s):
            if i == len(s)-1:
                num += d.get(x)
            else:
                if d.get(x)>=d.get(s[i+1]):
                    num += d.get(x)
                else:
                    num = num - d.get(x)
        return num
```



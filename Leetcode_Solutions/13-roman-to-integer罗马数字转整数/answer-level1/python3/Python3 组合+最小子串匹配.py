### 解题思路
**紧紧**抓住**核心思想**：
- 按照优先度，匹配单个罗马字符或一对罗马字符，完成转换

题中的进位有7个: [I,V,X,L,C,D,M]，分别代表[1,5,10,50,100,500,1000]
根据罗马数字的规则和特性，假设**当前一进位**是**A**，**当前五进位**是**B**，**当前十进位**是**C**，那么当前进位的单位组合有[φ,A,AA,AAA,AB,B,BA,BAA,BAAA,AC]，代表**当前进位的0~9**。当A表示个位，十位，百位，千位时，组合都成立（根据题意，不讨论千位M的五千进位和万进位）。

对上述单位组合进行**优先度+最小子串拆解**，得到[AB,AC,A,B]，优先度从高到低。罗马数字转换是**左结合方向（左高进位右低进位，所以是从左往右的左结合）**，但其中**AB,AC是右结合**，两个符号不能拆解，所以优先度高；而AA,AAA可以拆解为单个A，优先度低；BA,BAA,BAAA是左结合，所以优先度也低。
根据每个进位最小子串，建立map，我这里分开建立单符号map和双符号map。
因为最大匹配子串是两个字符，所以用**长度2的划窗**遍历字符串，最后将结果累加，得到答案。
OK，以上就是解题思路啦 :D

### 代码

```python3 []
class Solution:
    def romanToInt(self, s: str) -> int:
        char_map = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        carry_map = {'IV':4, 'IX':9, 'XL':40, 'XC':90, 'CD':400, 'CM':900}
        res = 0
        
        skip = False
        for ci,cj in zip(s, s[1:]+'$'):
            if skip:
                skip = False
            else:
                if (ci+cj) in carry_map:
                    skip = True
                    # print(ci+cj)
                    res += carry_map[ci+cj]
                else:
                    # print(ci)
                    res += char_map[ci]
        return res
```
稳定精巧，简洁高效，即吾追求
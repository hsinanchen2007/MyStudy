
## 人生苦短，我用python！简单的思路最适合大多数人！
python的精髓在于简单，灵活，用少的代码完成别的语言相同的工作！

最长回文字符串，我们看到这道题目，首先想到的是我们需要哪些数据，怎么操作！
### 数据
1. 待处理的字符串，官方会给；
2. 用来存储当前最长回文字符串的变量，控制子串长度的索引变量；
3. 一些其他的中间变量；

### 思路
做过判断一个字符串是否是回文字符串的那道题时我们就知道，从中心向两边扩展依次比较对称位置是否相等就可以了。
从第一个字符往后遍历，把每个字符都当作中心去向两边扩散，当碰到边界停下；

### 两种情况
1. 子串的形式为  ddbaabdd
2. 子串的形式为  ddbabdd
3. 
### 边界
无论两种情况的哪一种，边界都是相同的， 即为下面while循环的条件
1. 边界1是当控制子串的索引变量向左向右有一个碰到母串的边了；
2. 边界2是字串在扩散的过程中，左边字符不等于右边字符，这样就不是回文字符串了；


 ```python
class Solution:
    def longestPalindrome(self, s: str) -> str:
        temp, max_p, length = "", "", len(s)  # 初始化一些要用的数据
        for index in range(length): # 把每个字符都当作中心
            index_left, index_right = index, index

            def compare(l, r):  # 中心向两边扩散，两种形式的边界相同，所以一个函数搞定！
                while l != -1 and r != length and s[l] == s[r]: # 边界
                    l, r = l-1, r+1  # 扩散
                return s[l+1:r] if l == -1 or r == length else s[l+1:r]   # 因为不同的边界条件返回的子串索引取值是有规律的！

            temp = compare(index_left, index_right)  # 判断形式1是否存在
            max_p = temp if len(temp) > len(max_p) else max_p  # 判断是否比当前的回文字符串更长

            try:s[index+1]
            except:continue

            if s[index] == s[index+1]:  # 判断形式2是否存在
                left, right = index, index + 1
                temp = compare(left, right)  # 扩散
                max_p = temp if len(temp) > len(max_p) else max_p   # 判断是否比当前的回文字符串更长
        return max_p  # 返回最长回文字符串
```
## 代码解读：
**max_p** 是用来存放当前最长的回文子串；
**compare**函数，因为子串的形式只有两种，并且两种的边界都相同，那我们可以把两种给统一起来，用一个**compare**函数调用两次来完成；
**try和except**用异常捕获来判断当前字符的右面是否还有字符；当然也可以用当前字符索引和母串长度的关系来判断；

###### 刚刚接触python不久！如果觉得能有所帮助的话，可以关注一下我的csdn博客（csdn博客：叫我明同学），也可以加一下我的python学习交流群：625988679 ；本人最近也是在准备考研，您的关注和支持可以无形之中增加我在复试中的表现，谢谢您！

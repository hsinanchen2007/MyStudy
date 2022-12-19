### 解题思路
![QQ截图20200319195355.png](https://pic.leetcode-cn.com/6530cc58b08c3ce7c3b66d3e422b161fa9b466a8034b288eea67bacc585d407e-QQ%E6%88%AA%E5%9B%BE20200319195355.png)
最长  =原字符串长度-出现次数为奇数的不同字符的个数+1(存在次数奇数字符的情况) 
   或 =原长（没有出现次数为奇数的字符)

好久没写Python了，都不敢搞骚操作，写起来保守的一比

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        l=len(s)
        flag=False
        for each_char in set(s):
            count_char=s.count(each_char)
            if count_char%2==0:
                continue
            else:
                flag=True#存在出现次数为奇数的字符
                l-=1
        if flag==True:
            return l+1
        else:
            return l
```
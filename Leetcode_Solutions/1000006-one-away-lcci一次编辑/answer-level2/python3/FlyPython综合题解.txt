公众号持续更新leetcode题解，欢迎关注。

![](https://pic.leetcode-cn.com/2a15d78b4b977527a4d95f2bb238db8c82b7d133878dbf168b4b972271818c58.jpg)


题目汇总： [leetcode](http://flypython.com/leetcode/) 

#### 思路

首先，我们来理解一下题意。有三种编辑操作：
- 插入一个字符
- 删除一个字符
- 替换一个字符

现在有两个字符串，问是否可以用一次或零次编辑把一个字符变成另外一个字符。

我们可以把插入或者删除一个字符归为一类，这一类就是这两个字符串长度相差为1，而且长的字符串多一个字符，其余字符都相同。替换一个字符归为一类，这一类，两个字符串有一个不相同的字符，但它们的长度相等。

具体分为两大分支来处理：
1. 字符串长度相同 -> 遍历一遍找出不同等的字符，如果超过1次不同，则返回False
2. 字符串长度不同 -> 遍历，长的字符串丢下一个字符与另外一个字符串比较，如果相同就返回True

#### 方案代码

```
class Solution:
    def oneEditAway(self, first: str, second: str) -> bool:
        if abs(len(first)-len(second)) > 1:
            return False
        
        replace_count = 0
        if len(first) == len(second):
            for i in range(len(first)):
                if first[i] != second[i]:
                    replace_count += 1
                if replace_count >= 2:
                    return False
                
            return True
            
        if len(second) > len(first):
            first,second = second, first

        if len(first) > len(second):
            for i in range(len(first)):
                if first[0:i] + first[i+1:] == second:
                    return True
            return False
```
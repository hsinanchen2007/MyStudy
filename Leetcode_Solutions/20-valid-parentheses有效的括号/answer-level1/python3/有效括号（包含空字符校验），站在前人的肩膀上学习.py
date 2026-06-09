参考前辈的方法，自己又深入了一下，看了好些题解，好像都没提到空字符的问题，基于@Krahets的结题思路，画了一下流程图，改写了一下这个方法。
Krahets的题解见：[https://leetcode-cn.com/problems/valid-parentheses/solution/valid-parentheses-fu-zhu-zhan-fa-by-jin407891080/ ]()

![循环体i 2.png](https://pic.leetcode-cn.com/c2fad3c2b79ef44d62ffa6654bb6c382af5e3b4c46cc5e5b51d673e6126d0d0d-%E5%BE%AA%E7%8E%AF%E4%BD%93i%202.png)
代码如下：
```
class Solution:
    def isValid(self, s: str) -> bool:
        dic1 = {'(':')','[':']','{':'}'}
        stack = []
        for i in s:
            # print(i)
            if i in dic1:
                stack.append(i)
            elif len(stack)==0  : 
                return False
            elif i==" ":
                continue
            elif dic1[stack[-1]]!=i:
                    return False
            else:
                stack.pop()
        return len(stack)==0
test = Solution()
test.isValid('{[ ][]()  }')
```


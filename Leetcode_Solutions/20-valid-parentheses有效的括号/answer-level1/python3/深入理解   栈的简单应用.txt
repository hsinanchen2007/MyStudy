思路：观察后发现，各种类型的左括号，只有在与相对应的右括号，逆序排列的时候，才是正确的。（比如，“{[(”，对应右括号必为“)]}”）因此，我们只需要验证左类型括号，与相对应的右类型括号逆序，即可完成题解。

利用栈的思想：由于是元素逆序排列，使用栈是很好的选择。先进后出的元素，刚好可以得到逆序的元素。

根据题目特征，需要注意的地方：
1. 结果。
栈为空，最终结果为True
2. 左右括号对应。
为了比较左类型括号和右类型括号，是否相对应，创建了一个表map
3. pop()操作时表为空。
设置一个伪值“#”，直接判断为False


```
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        map = {")":"(", "]":"[", "}":"{"}
        
        for char in s:
            if char in map:
                top_item = stack.pop() if stack else '#'
                if map[char] != top_item:
                    return False
            else:
                stack.append(char)
        return not stack
```

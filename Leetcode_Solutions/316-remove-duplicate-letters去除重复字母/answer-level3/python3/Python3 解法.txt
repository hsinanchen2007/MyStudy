### 解题思路
思路参考了liweiwei大神的，在他代码上简化了一下。添加的时候如果当前添加的字符比之前的小，就看能不能把之前的删掉，这样保证stack队列里面的字符都是有序并且无法继续删除的了。
后面遍历发现stack里面有就直接忽略。
![image.png](https://pic.leetcode-cn.com/756b74ad81fc8f12fbf1aa1ec3560986a1db78786a9af6993185b75c416918d9-image.png)


### 代码

```python3
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        stack = [0]
        for i, v in enumerate(s):
            remain = s[i+1:]
            if v in stack:
                continue

            while stack[1:]:
                if stack[-1] >= v and stack[-1] in remain:
                    stack.pop()
                    continue

                break

            stack.append(v)

        return ''.join(stack[1:])
```
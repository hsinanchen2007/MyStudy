### 解题思路
此处撰写解题思路
思想都写在代码和注释里
### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        s,s1 = re.sub(' +',' ',s).strip()+" ",""#消除多余的空格以及左右两边的空格
        stack = []#建立列表，利用栈的思维后进先出原则
        for i in s:#将单子逐个输入列表
            if i != ' ':
                s1=s1+i
            else:
                stack.append(s1)
                s1 = ""
        l = -1-len(stack)
        for j in range(-1,l,-1):#将单词按照栈的性质逐个输出 既从后向前输出 然后拼接
            s1 = s1+stack[j]+" "
        s1 = s1.strip()
        return s1
            
```
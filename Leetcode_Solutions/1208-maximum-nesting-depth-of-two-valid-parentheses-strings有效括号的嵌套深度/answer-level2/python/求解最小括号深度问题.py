### 解题思路
此处撰写解题思路    
刚开始也是没有看懂题目，看了一下评论才看懂了这个题是什么意思，面向语文编程（哈哈哈）
简单来说就是遍历数组，把'('')'这一对一对的括号分成AB两组，A组用0表示，B组用1表示，

具体解法就是通过判断每个单括号所在的深度,(这里深度默认为0)，偶数深度就放A组，奇数深度就放B组
运用最基础的方法解决了这个问题
### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        li1 = []
        for i in range(len(seq)):
            if i == 0 :
                depth = 0

            elif seq[i] == '(' and seq[i-1] == '(':
                depth += 1

            elif seq[i] == ')' and seq[i-1] == ')':
                depth -= 1
            
            li1.append(depth %2)
        return li1
```
![d82d49effbd1196a2239c3996d74291.png](https://pic.leetcode-cn.com/2c18047e1b35cfae0513878ee2976456ebf1b0a3bafecb25f7802d7884130e82-d82d49effbd1196a2239c3996d74291.png)

本方法主要使用了**迭代**（循环）和**栈**数据结构
在处理字符串时使用了**正则表达式**

```python []
import re  # 使用re模块分割字符串


class Solution:
    def str2tree(self, s: str) -> TreeNode:
        if not s:  # 排除s为空的特例
            return None
        s = re.split(r'(?=[()])|(?<=[()])', s)
        # 把字符串切割成‘（’、‘）’和数字，具体方法是把隔断点设在‘（’和‘）’的前面和后面
        s = [i for i in s if i]
        # 正则表达式会吧空字符串也匹配进去，所以要把空字符串删掉
        root = TreeNode(int(s[0]))  # 把第一个数字设置为根节点
        stack = [(root, 'white')]
        # 这里给每个node配了一个color属性，用来表示node是否已经连过子node了（如果没有，就用‘white’），连过了就用‘gray’
        i = 1  # 因为i=0的情况已经处理过了（设为root，放进stack），所以从1开始遍历s
        while i < len(s):
            if s[i] == '(':  # 如果是左括号，那么后面一个肯定是个子节点
                i += 1
                new_node = TreeNode(int(s[i]))  # 提取出后面一个子节点new_node的value
                node, color = stack[-1]
                if color == 'white':  # 如果栈的最外边的node的color是‘white’，表示它还没左孩子
                    node.left = new_node  # 把node的左孩子设为子节点
                    stack[-1] = (node, 'gray') # 把node的color设为‘gray’
                else:
                    node.right = new_node  # 如果node的color是‘gray’，表示它已经有左孩子了
                stack.append((new_node, 'white')) # 把node的右孩子设为子节点
            if s[i] == ')':  # 如果是右括号，那么把node出栈（这个node已经处理完了）
                stack.pop()
            i += 1
        return root
                    
```



```
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


'''
思路
一个字数的序列化字符串用[ ] 左右包裹，方括号中第一个值是根节点的数值，后面跟着空格分隔
的多个子树的序列化字符串
'''

class Codec:
    def serialize(self, root: 'Node') -> str:
        if root is None:
            return ''

        if root.children is None or len(root.children) == 0:
            return str(root.val)

        buf = str(root.val)
        for child in root.children:
            buf += ' ' + self.serialize(child)

        #print('[' + buf + ']')
        return '[' + buf + ']'

    def buildTree(self, s, start, end, start2end) -> Node:
        if s == '':
            return None

        if s[start] != '[':
            return Node(int(s[start:end+1]), [])

        nodes = []
        i = start + 1
        while i <= end:
            if s[i].isnumeric():
                j = i
                while s[j].isnumeric():
                    j += 1
                nodes.append(self.buildTree(s, i, j-1, start2end))
                i = j+1
            elif s[i] == '[':
                nodes.append(self.buildTree(s, i, start2end[i], start2end))
                i = start2end[i]
            else:
                i += 1

        #print(s, start, end, nodes)
        root = nodes[0]
        root.children = nodes[1:]
        return root

    def deserialize(self, data: str) -> 'Node':
        if data == '':
            return None

        # 从左到右找每一个左括号与其配对的右括号的位置
        stack = []
        start2end = {}
        for i, ch, in enumerate(data):
            if ch == '[':
                stack.append(i)
            elif ch == ']':
                start2end[stack[-1]] = i
                stack.pop(-1)

        return self.buildTree(data, 0, len(data)-1, start2end)
```

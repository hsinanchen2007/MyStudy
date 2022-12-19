### 解题思路
```javascript []

//递归
var preorder = function(root) {
  if (!root) return [];

  var res = [];

  function recusion(root, res) {
    if (!root) return;

    res.push(root.val);
    for (var i = 0; i < root.children.length; i++) {
      recusion(root.children[i], res);
    }
  }
  recusion(root, res);
  return res;
};

```
```python []
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        if root == None:
            return []
        stack, output = [root], []

        while stack:
            node = stack.pop()
            if node != None:
                output.append(node.val)
            if node.children:
                stack.extend(node.children[::-1])  # 这里需要反向切片, 即将最左边的先执行

        return output

```

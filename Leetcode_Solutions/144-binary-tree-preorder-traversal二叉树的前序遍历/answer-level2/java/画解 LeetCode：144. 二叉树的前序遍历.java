## 递归解法

### 思路

- 标签：`递归`
- 先序（根）遍历：根左右。先打印根节点，再递归左右子树，需要结合递归的函数调用栈理解
  - 默认方法没有 list 参数，新增带有参数的方法解决
  - 不用基准条件，当左右子树执行完成之后，自动跳出递归

### 代码

```Java []
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        helper(root, list);
        return list;
    }

    // 利用 helper，加 list 条件
    private void helper(TreeNode root, List<Integer> list) {
        if (root == null) {
            return;
        }
        list.add(root.val);
        if (root.left != null) {
            helper(root.left, list);
        }
        if (root.right != null) {
            helper(root.right, list);
        }
    }
}
```

## 非递归解法


![image-20191215085413300](https://pic.leetcode-cn.com/e7a338fd2d822e135fdab06bb8ffb7dc7a3256e389f5ec90d02643c614b08880.jpg)

### 思路

- 标签：`栈`
- 利用栈存储节点（不是存放值），相当于实现递归的函数调用栈
  - 获取当前节点的左子节点，如果节点不为空，压入栈；如果节点为空，弹出栈顶元素，并获取栈顶元素的右子节点，如果节点为空，再次弹出栈顶元素，如果节点不为空，压入栈
  - 入栈：节点不为空；出栈：节点为空

### 代码

```Java []
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        Deque<TreeNode> stack = new LinkedList<>();
        List<Integer> list = new ArrayList<>();
        TreeNode curr = root;
        while (curr != null || stack.size() > 0) {
            while (curr != null) {
                stack.push(curr);
                list.add(curr.val);
                curr = curr.left;
            }
            curr = stack.pop().right; // 当没有右子树时，只删除最上面节点
        }
        return list;
    }
}
```



Java递归写法，
执行用时 :6 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :39.4 MB, 在所有 Java 提交中击败了100.00%的用户
![image.png](https://pic.leetcode-cn.com/f065ca46404f6ca04460a02717c7d5b441e9ca776046f024448911d27565a8a7-image.png)

1、遇到左括号就往下递归
2、遇到右括号就返回一步
3、递归函数内 按顺序处理：
  1）获取当前节点自己的值
  2）如果为左括号，就递归构建左子树
  3）重复一遍，如果为左括号，就递归构建右子树
  4）如果有右括号，就返回上一次
  注意 每一步都要更新索引位置

代码如下：
```
class Solution {
    public TreeNode str2tree(String s) {
        if (s == null || s.length() < 1) {
            return null;
        }
        TreeNode node = new TreeNode(0);
        buildSubTree(node, s, 0);
        return node;
    }

    private static int buildSubTree(TreeNode node, String string, int index) {
        int i = index;
        while ((string.charAt(i) >= '0' && string.charAt(i) <= '9') || string.charAt(i) == '-') {
            i++;
            if (i >= string.length()) {
                break;
            }
        }
        node.val = Integer.valueOf(string.substring(index, i));
        if (i < string.length() && string.charAt(i) == '(') {
            node.left = new TreeNode(0);
            i = buildSubTree(node.left, string, i + 1) ;
        }
        if (i < string.length() && string.charAt(i) == '(') {
            node.right = new TreeNode(0);
            i = buildSubTree(node.right, string, i + 1) ;
        }
        if (i < string.length() && string.charAt(i) == ')') {
            return ++i;
        }
        return i;
    }
}
```




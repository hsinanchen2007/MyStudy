![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/0afa84ef1c8854c32d45a8bf369190d10a3f5b69ca8a7de03f7f006c70d06275-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)


### 代码

```java
class Solution {
    HashMap<Integer, Integer> map = new HashMap<>();

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder == null || inorder == null) return null;
        if (preorder.length == 0) return null;
        for (int i = 0; i < inorder.length; i++) {
            map.put(inorder[i], i);
        }
        return buildTree(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);

    }

    public TreeNode buildTree(int[] pre, int s1, int e1, int[] ino, int s2, int e2) {
        if (s1 == e1) return new TreeNode(pre[s1]);
        // 获取中序遍历的数组根节点的序号
        int num = map.get(pre[s1]);
        // 左边结点的总个数
        int lefnum = num - s2;
        // 右边结点的总个数
        int rignum = e2 - num;
        TreeNode head = new TreeNode(pre[s1]);
        if (num == s2) {
            head.left = null;
        } else {
            head.left = buildTree(pre, s1 + 1, s1 + lefnum, ino, s2, num - 1);
        }

        if (num == e2) {
            head.right = null;
        } else {
            head.right = buildTree(pre, s1 + lefnum + 1, e1, ino, num + 1, e2);
        }
        return head;
    }
}
```
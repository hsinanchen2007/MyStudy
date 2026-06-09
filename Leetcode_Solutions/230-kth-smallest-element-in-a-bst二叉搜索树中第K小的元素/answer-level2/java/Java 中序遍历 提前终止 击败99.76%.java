看了一圈，Java 的比较少，就还是写下题解吧
![image.png](https://pic.leetcode-cn.com/a5f6e6ebab1d057e8de6a16c7299b85851ef49d6174c7798a74175e2675c55e2-image.png)

思路很清晰，对于二叉搜索树，中序遍历即可得到有序的排列，取第k个数即可：
```
public int kthSmallest(TreeNode root, int k) {
    cnt = k;
    inOrder(root);
    return val;
}
private int cnt; //计数
private int val; // 保存结果

private void inOrder(TreeNode root){
    if (root == null) return;
    inOrder(root.left);
    cnt--;
    if (cnt == 0){
        val = root.val;
        return;
    }else if (cnt < 0) // 多一层判断，提高速度
        return;
    inOrder(root.right);
}
```

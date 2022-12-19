### 解题思路
遍历获取有序数组，然后二分构建平衡树。

### 代码

```java
class Solution {

    int [] val = new int[10000 + 1];
    int cnt = 0;

    public TreeNode balanceBST(TreeNode root) {
        travlel(root); //便利获取有序数组

        return cb(0, cnt); //二分构造平衡
    }

    private TreeNode cb(int l, int r){
        if(l == r){
            return null;
        }

        int mid = l + r;
        mid /= 2;

        TreeNode root = new TreeNode(val[mid]);

        root.left = cb(l, mid);
        root.right = cb(mid + 1, r);

        return root;
    }

    //中序遍利
    private void travlel(TreeNode root){
        if(root == null){
            return ;
        }

        travlel(root.left);
        val[cnt++] = root.val;//获取元素
        travlel(root.right);
    }
}
```
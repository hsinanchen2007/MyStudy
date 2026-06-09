/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/11
 * 
 * 解题思路: 二叉搜索树的特点 中序遍历后是有序的（升序）
 * 
 */
```
public class leetcode783 {

    List<Integer> list = new ArrayList<>();
    public int minDiffInBST(TreeNode root) {
        inOrder(root);
        int diff = Integer.MAX_VALUE;
        for(int i = 0;i < list.size() - 1;i++){
            if(list.get(i + 1) - list.get(i) < diff){
                diff = list.get(i + 1) - list.get(i);
            }
        }
        return diff;
    }

    public void inOrder(TreeNode root){
        if(root == null) return ;

        inOrder(root.left);
        list.add(root.val);
        inOrder(root.right);
    }

    public static void main(String[] args) {

    }
}

```
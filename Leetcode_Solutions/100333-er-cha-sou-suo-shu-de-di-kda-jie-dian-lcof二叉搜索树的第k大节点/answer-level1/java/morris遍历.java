### 解题思路
神级遍历morris，你值得拥有
https://zhuanlan.zhihu.com/p/101321696

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    List<Integer> list=new ArrayList<>();
    public int kthLargest(TreeNode root, int k) {
        if(root==null){
            return -1;
        }
        In(root);
        if(k>list.size()){
            return -1;
        }
        return list.get(list.size()-k);
    }
    public void In(TreeNode root){
        if(root==null){
            return;
        }
        TreeNode cur=root;
        TreeNode mostRight=null;
        while(cur!=null){
            mostRight=cur.left;
            if(mostRight!=null){
                while(mostRight.right!=null&&mostRight.right!=cur){
                    mostRight=mostRight.right;
                }
                if(mostRight.right==null){
                    mostRight.right=cur;
                    cur=cur.left;
                    continue;
                }else{
                    mostRight.right=null;
                }
            }
            list.add(cur.val);
            cur=cur.right;
        }
    }
}
```
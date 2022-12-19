### 解题思路
https://www.zhihu.com/people/god-jiang

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> listAll=new ArrayList<>();
        if(root==null){
            return listAll;
        }
        Stack<TreeNode> s1=new Stack<>();
        Stack<TreeNode> s2=new Stack<>();
        s1.push(root);
        int level=0;
        while(!s1.isEmpty() || !s2.isEmpty()){
            List<Integer> list=new ArrayList<>();
            if(level++%2==0){
                while(!s1.isEmpty()){
                    TreeNode cur=s1.pop();
                    list.add(cur.val);
                    if(cur.left!=null){
                        s2.push(cur.left);
                    }
                    if(cur.right!=null){
                        s2.push(cur.right);
                    }
                }
            }else{
                while(!s2.isEmpty()){
                    TreeNode cur=s2.pop();
                    list.add(cur.val);
                    if(cur.right!=null){
                        s1.push(cur.right);
                    }
                    if(cur.left!=null){
                        s1.push(cur.left);
                    }
                }
            }
            listAll.add(list);
        }
        return listAll;
    }
}
```
### 解题思路
利用ArrayList的add(element))和add(index,element)轻松搞定

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
    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> levelOrder(TreeNode root) {
        addLevel2List(0,root);
        return res;
    }
    private void addLevel2List(int depth,TreeNode node){
        if(node == null){
            return;
        }
        if(res.size()<=depth){
            List<Integer> list = new ArrayList<>();
            list.add(node.val);
            res.add(list);
        }else{
            if(depth%2==0){
                res.get(depth).add(node.val);
            }else{
                res.get(depth).add(0,node.val);
            }
        }
        addLevel2List(depth+1,node.left);
        addLevel2List(depth+1,node.right);
    }
}
```
### 解题思路
此处撰写解题思路

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
 import java.util.Stack;
import java.util.ArrayList;
import java.util.List;
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList();
        Stack<TreeNode> s = new Stack();
        s.push(root);
        while(!s.empty()){
            root = s.pop();
            if(root!=null){
                list.add(root.val);
                s.push(root.left);
                s.push(root.right);
            }
        }
        List<Integer> res = new ArrayList();
        for(int i = list.size()-1; i>=0;i--){
            res.add(list.get(i));
        }
        return res;
    }
}
```
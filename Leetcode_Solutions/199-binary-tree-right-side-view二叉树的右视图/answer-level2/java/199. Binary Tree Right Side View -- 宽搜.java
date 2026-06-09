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
    
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new LinkedList();
        if(root == null) return res;
        
        Queue<TreeNode> q = new LinkedList();
        q.add(root);
        while(!q.isEmpty()){
            int len = q.size();
            for(int i = 0; i < len; i++){
                TreeNode tmp = q.remove();
                if(i == len-1) {res.add(tmp.val);}
                if(tmp.left != null) q.add(tmp.left);
                if(tmp.right != null) q.add(tmp.right);
            }
        }
        
        return res;
    }
}
```


> python3版本

```python
from typing import List

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root is None:
            return []

        result = []
        q = [root]

        while q:
            level_size = len(q)
            result.append(q[-1].val)
            for _ in range(level_size):
                front = q.pop(0)
                if front.left:
                    q.append(front.left)
                if front.right:
                    q.append(front.right)
            
        return result

```
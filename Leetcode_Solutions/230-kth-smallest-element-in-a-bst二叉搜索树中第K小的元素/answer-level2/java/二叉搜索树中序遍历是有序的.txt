> 二叉搜索树的一个重要性质，中序遍历有序，所以我们只需要中序遍历这个树，一边遍历一边计数，找到k就直接返回。
```
import java.util.*;
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        /*中序遍历，第k个就是了*/
        Stack<TreeNode> stack = new Stack<>();
        if (root != null)
            stack.push(root);
        int cnt = 0;
        while (!stack.empty()){
            while(root != null){
                root = root.left;
                if(root != null)
                    stack.push(root); // 一直往左走，走到底。
            }
            root = stack.pop(); // 弹出栈顶，也就是最左边的。
            if(root != null){
                cnt += 1;
                if (cnt == k)
                    return root.val;
                root = root.right;
                if(root != null)
                    stack.push(root);
            }       
        }
        return -1;
    }
}
```
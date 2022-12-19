### 解题思路
此题做法就是简单的层序遍历，层序遍历使用队列即可完成。
每出队一个元素，将其左右孩子入队，循环，直到队列为空。

### 代码

```java
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    
    public int[] levelOrder(TreeNode root) {
        if(root == null) return new int[0];
        Queue<TreeNode> queue = new LinkedList<>();
        List<Integer> list = new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty()){
            TreeNode cur = queue.remove();
            list.add(cur.val);
            if(cur.left != null)
                queue.add(cur.left);
            if(cur.right != null)
                queue.add(cur.right);
        }
        int[] res = new int[list.size()];
        int i = 0;
        for (int n : list) {
            res[i++] = n;
        }
        return res;
    }
}
```
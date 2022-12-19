# 解法一 递归
***假设有两个二叉树***
![两个二叉树.png](https://pic.leetcode-cn.com/a19dde8083d3e3181b751b5b26e86110c09edbf6dc515d0f17f74e0f6fbafd50-%E4%B8%A4%E4%B8%AA%E4%BA%8C%E5%8F%89%E6%A0%91.png)
如果互为对称，则必满足三个条件：
1. 根节点相等（相等也是对称的特殊情况）；
2. A的左子树和B的右子树互为镜像
3. A的右子树和B的左子树互为镜像
# 解法二 BFS迭代
BFS套路：
- 申请队列
- 队列初始化
- 当队列不为空{从队列取出，【一顿操作】满足的元素再进队列}
对于二叉树[1,2,2,3,4,4,3]
左子树2和右子树2进队列 queue：2 2 
队列弹出两个元素，判断是否相等 node1 2 == node2 2 queue： 
将node1的左子树和node2的右子树入队列
将node1的右子树和node2的左子树入队列 queue：3 3 4 4
### 代码

```java
class Solution {
    public boolean isSymmetric(TreeNode root) {
        //方法一：递归
        //return isMirror(root, root);

        //方法2：队列迭代
        if(root == null){
            return true;
        }
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.offer(root.left);
        queue.offer(root.right);

        while(queue.size() > 0){
            TreeNode node1 = queue.poll();
            TreeNode node2 = queue.poll();

            if(node1 == null && node2 == null){
                continue;
            }
            if(node1 == null || node2 == null){
                return false;
            }
            if(node1.val == node2.val){
                queue.offer(node1.left);
                queue.offer(node2.right);
                queue.offer(node1.right);
                queue.offer(node2.left);
            }else{
                return false;
            }
        }
        return true;

    }

    public boolean isMirror(TreeNode node1, TreeNode node2){
        if(node1 == null && node2 == null){
            return true;
        }
        if(node1 == null || node2 == null){
            return false;
        }
        //node1树和node2数根节点相等
        if(node1.val == node2.val){
            //则比较node1的左、node2的右 以及 node1的右、node2的左
            return isMirror(node1.left, node2.right) && isMirror(node1.right, node2.left);
        }
        return false;
    }
}
```
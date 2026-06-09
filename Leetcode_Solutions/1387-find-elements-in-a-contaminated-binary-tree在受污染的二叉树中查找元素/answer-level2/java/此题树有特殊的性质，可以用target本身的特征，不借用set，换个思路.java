用Set集合我估计大家应该都知道怎么写了，这里换一个思路，find时候先递归回到根元素，然后从节点往下递推，用set空间复杂度是O(N)，用这个方式空间复杂度是O(logN),时间复杂度也是O(logN)，其实新思路连在构造时候还原二叉树都不用了，find的结果不受二叉树是否污染影响。算是对空间和时间的一个折中选择，给其他同学提供一个想法吧
```
public class FindElements {

    private TreeNode root;

    public FindElements(TreeNode root) {
        // 层次遍历还原
        root.val = 0;
        this.root = root;
        TreeNode node = root;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(node);
        while (!queue.isEmpty()){
            node = queue.poll();
            if (node.left != null){
                node.left.val = (node.val << 1) + 1;
                queue.offer(node.left);
            }
            if (node.right != null) {
                node.right.val = (node.val << 1) + 2;
                queue.offer(node.right);
            }
        }
    }

    public boolean find(int target) {
        // 不用set的话，可以采用满二叉树遍历的方法
        // target == ((target - 1) / 2 * 2 + 1) 满足这个条件的，就是其父节点的左孩子，否则是右孩子，至于为什么可以画图理解
        // 然后target = (target - 1) / 2 往上递归，每次倒序记录是这个是左还是右（用个栈来记录），直到根节点
        // 然后再从根节点按照栈的弹出顺序，往左孩子或者右孩子递推，中间如果有空节点，则找不到，否则是找到
        Deque<Boolean> stack = new LinkedList<>();// 双端队列模拟栈
        while (target > 0){
            stack.push(target == ((target - 1) / 2 * 2 + 1));// 是否是左孩子
            target = (target - 1) >> 1;
        }
        TreeNode node = this.root;
        while (!stack.isEmpty()){
            if (stack.pop()){// 是左孩子，往左节点递推
                node = node.left;
            }else {// 否则往右节点递推
                node = node.right;
            }
            if (node == null){
                return false;
            }
        }
        return true;
    }
}
```

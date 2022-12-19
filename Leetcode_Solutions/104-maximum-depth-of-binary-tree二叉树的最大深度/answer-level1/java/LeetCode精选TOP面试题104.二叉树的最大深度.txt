### 题目描述
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
### 思路
**思路1：**  非递归
借助任意一种二叉树的遍历方法进行最大深度的求解，先序、中序、后续都可以，代码大体流程是相同的，层次遍历的话是单独的模式。借助两个栈，一个存储当前结点，一个存储当前结点的深度，那么通过比较当前深度与最大深度，不断更新最大深度，当遍历结束后，就可以直接返回最大深度了。
**思路2：**  递归
递归的方法也不难理解，当遇到叶子节点就返回0 （这也是这个递归程序的边界） ，否则继续递归，并返回深度值加1。理解不了的画个递归的图解就行了。
### 代码（Java实现）
**1.非递归代码**
```
import java.util.Stack;
public class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null){
       		// 空树，深度是0
            return 0;
        }
        
        // 前序遍历 - 借助栈
        Stack<TreeNode> stack = new Stack<TreeNode>();// 存放结点
        Stack<Integer> remDeep = new Stack<Integer>();// 存放深度
		
		// 定义一个新的结点指向目标树的根节点，用于遍历
        TreeNode tmp = root;
        int maxDepth = 0；	// 记录最大深度
        int curDepth = 0;	// 记录遍历时的‘当前’深度

        curDepth ++ ;		// 树不空，当前深度肯定>=1，所以先加上1
        // 先序遍历的模式
        while (!stack.isEmpty() || tmp != null){
            while (tmp != null){
            	// 不断向左
                stack.add(tmp);
                remDeep.add(curDepth);
                tmp = tmp.left;
                curDepth ++;
            }
            
            tmp = stack.pop();			// 退回到当前结点的双亲节点
            curDepth = remDeep.pop();	// 当前深度也退回到双亲节点所在的深度
            if (tmp.right == null && tmp.left == null){
                if (curDepth > maxDepth){
                	// 更新最大深度
                    maxDepth = curDepth;	
                }
            }
            tmp = tmp.right; // 访问右子树
            curDepth ++;	 // 当前深度+1
        }
        return maxDepth;
    }
}
```
**2.递归代码**
```
public class Solution2 {
    public int maxDepth(TreeNode root) {
        if (root == null){		// 叶子节点是边界值
            return 0;	
        }
        else {
            int ldepth = maxDepth(root.left);	// 递归求左子树深度
            int rdepth = maxDepth(root.right);	// 递归求右子树深度
            // 哪个大哪个就是当前子树的最大深度，
            // 层层返回之后就是目标数的最大深度
            return ldepth > rdepth ? ldepth + 1 : rdepth + 1;
        }
    }
}
```

1. 关于复杂度
    1.1 时间复杂度为O(n)
    1.2 空间负责度为O(n)
2. 我的解题思路
    2.1 定义一个list以及栈(list为结果list，stack用于存储计算过程中的结点)
    2.2 循环直到op为空或者栈为空
        2.2.1 循环深度遍历op的左孩子并把它加入栈
        2.2.2 获取栈顶结点
              2.2.2.1 如果栈顶结点有右孩子，改变op的指向以及将原结点的右孩子设置为空
              2.2.2.2 如果栈顶结点没有右孩子，将它的值加入到结果list中
3. 提交记录
    3.1 力扣中耗时2ms,消耗34.2MB内存
    3.2 leetcode中耗时1ms,消耗34.7MB内存
4. Q&A

```
/**
 * Problem
 *      145.Binary Tree Postorder Traversal
 * Grade of difficulty
 *      Hard
 * Related topics
 *      98. Validate Binary Search Tree
 *      110.Balanced Binary Tree
 *      111.Minimum Depth of Binary Tree
 *      129.Sum Root to Leaf Numbers
 *      687.Longest Univalue Path
 * @author cartoon
 * @version 1.0
 */
 class Solution {

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(n)
     * 2.how I solve
     *     2.1 define a list list and a stack(list for record result,stack for cache treeNode)
     *     2.2 circulate with op!=null or stack.size()!=0
     *              2.2.1 circulate with op pointer to depth traverse left children
     *              2.2.2 get the top treeNode
     *                      2.2.2.1 if it has right children,change op to node's children and set quondam node's right children
     *                      2.2.2.2 if it hasn't right children,put node's val to result list
     * 3.About submit record
     *     3.1 2ms and 34.2MB memory in LeetCode China
     *     3.2 1ms and 34.7MB memory in LeetCode
     * 4.Q&A
     */
    private List<Integer> list;

    public List<Integer> postorderTraversal(TreeNode root) {
        list=new LinkedList<>();
        postOrder(root);
        return list;
    }

    private void postOrder(TreeNode op){
        if(op==null){
            return;
        }
        Deque<TreeNode> stack=new LinkedList<>();
        while(op!=null||stack.size()!=0){
            while(op!=null){
                stack.addFirst(op);
                op=op.left;
            }
            if(stack.size()!=0){
                TreeNode node=stack.peekFirst();
                if(node.right==null){
                    stack.removeFirst();
                    list.add(node.val);
                }
                else{
                    op=node.right;
                    node.right=null;
                }
            }
        }
    }

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(n)
     * 2.how I solve
     *     2.1 this solution is base on postOrder traverse
     *     2.2 go though left tree and right tree apart,and put root's val to result list
     * 3.About submit record
     *     3.1 1ms and 34.2MB memory in LeetCode China
     *     3.2 0ms and 36.2MB memory in LeetCode
     * 4.Q&A
     */
    private List<Integer> listByRecursion;

    public List<Integer> postorderTraversalByRecursion(TreeNode root) {
        listByRecursion=new LinkedList<>();
        postOrderByRecursion(root);
        return listByRecursion;
    }

    private void postOrderByRecursion(TreeNode root){
        if(root==null){
            return;
        }
        postOrderByRecursion(root.left);
        postOrderByRecursion(root.right);
        listByRecursion.add(root.val);
    }
}
```
如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出issue，我会及时处理
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路

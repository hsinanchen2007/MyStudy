```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
 /*错误思想，我想用递归，但是还想用栈，但是栈是迭代的时候用的，弄混了*/
 /*
    思路：
        若不为空
                则先加入列表，并且从sum中减去当前的val值
                    再判断若该节点为叶子节点
                        则判断sum值是否为0
                            若为0，则说明是一条路径，并将其复制到list列表中
                            若不为0，则在左右递归结束后进行列表删除操作
                    若该节点不是叶子节点 则将其
                       则左右递归
        若为空
                返回list列表
 */

 /*
    不理解的地方
        为什么我将回溯放在叶子节点情况不行
            我的想法：
                遇到叶子节点就是一个路径的完毕，无论是否成功路径，都应该删除列表最后的元素
            错误的地方在于：
                删除的节点只限于叶节点，而非叶节点无法被删除
            答案的想法：
                左右递归均完毕才算一条路径结束
                答案remove则是在每次的左右递归结束后，将该节点从列表中删除、
                保证了非叶节点也可以删除
 */
class Solution {
    List<List<Integer>> list = new LinkedList<List<Integer>>();
    List<Integer> inner = new LinkedList<Integer>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if(root==null)
        {
            return list;
        }
        sum = sum - root.val;
        inner.add(root.val);
        if(root.right==null && root.left==null)
        {
            if(sum==0)
            {
                list.add(new LinkedList<Integer>(inner));              
            }
        // inner.remove(inner.size()-1);
        }
        if(root.left!=null) pathSum(root.left,sum);
        if(root.right!=null) pathSum(root.right,sum);
        inner.remove(inner.size()-1);
        return list;                
    }
}
// inner.remove(inner.size()-1);
            /*错误思想
            这里else处理的不对，正常情况下，若sum不为零则说明此路不通
            应该回溯，即将inner中最后的一个元素清除
            但是sum则不需要进行 sum = sum - root.val操作，因为sum是递归调用的
            */
            // else
            // {
            //     // sum = sum + root.val;
            //     // inner.remove(inner.size()-1);
            // }
            // inner.remove(inner.size()-1);
```

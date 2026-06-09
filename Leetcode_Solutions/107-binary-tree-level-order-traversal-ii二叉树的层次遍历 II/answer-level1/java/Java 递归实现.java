1. 执行结果：
用时2ms，在所有Java提交中击败97.22%的用户
内存消耗37.3mb，在所有Java提交中击败29.84%的用户

2. 思路：
从顶层调用函数recursiveAddNodeValue()向下遍历，遍历函数的参数：node表示当前的节点，mylist表示要修改的List，level记录当前的层数
在递归的过程中，
- 1.如果当前节点为null，直接返回
- 2.如果当前节点是改层第一个元素，在List中新建空的一层
- 3.在List中添加节点的值
- 4.在递归调用他的右边，左边的节点

3. 代码：

```
 * /**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> mylist = new ArrayList<List<Integer>>();
        recursiveAddNodeValue(root, mylist, 1);
        return mylist;

    }

    public void recursiveAddNodeValue(TreeNode node, List<List<Integer>> mylist, int level) {
        if (node == null) {
            return;
        } else {
            //如果是这一层的第一个，就在list中新建一层
            if (level > mylist.size()) {
                List<Integer> tempList = new ArrayList<Integer>();
                mylist.add(0, tempList);
            }
            //添加自己的val值
            mylist.get(mylist.size() - level).add(0, node.val);
            //递归添加左右邻居
            recursiveAddNodeValue(node.right, mylist, level + 1);
            recursiveAddNodeValue(node.left, mylist, level + 1);
        }
    }
}
```



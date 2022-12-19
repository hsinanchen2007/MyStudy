### 解题思路
这里也是参考了其他人的思路， 也学到了新的思路， 以前总是用递归来将整个函数不断的自我调用，通过这个题目发现有更多的方式去解题，参考 “ 和上题一样” 的思路，这里的队列用的很巧妙， 通过同步的增减实现了队列的删除一层元素的同时又增加了一层的元素。

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
import java.util.*;
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> all_tree = new ArrayList<>();  //必须要设计一个能够装纳所有元素的总容易
        if(root == null) return all_tree;  //判断是否为空的情况
        Queue<TreeNode> tree_root = new LinkedList<>(); //我们需要一个暂时装纳所有树节点的动态数组
        tree_root.offer(root);
        while(!tree_root.isEmpty()){
            List<Integer> ele = new LinkedList<Integer>();
            int len = tree_root.size();
            for(int i = 0; i< len; i ++)  //为什么要定义 i ，一步步让它增加到 len 呢，一方面是队列的特性，尾加头减，定义长度可以使得队列刚好把以前添加的删除，而不会对新加入的删除，这也是定义 len 常量而不是用size的作用
            {
                TreeNode tem = tree_root.poll();
                if(tem.left != null){
                    tree_root.offer(tem.left);
                }
                if(tem.right != null){
                    tree_root.offer(tem.right);
                }
                ele.add(tem.val);
            }
            all_tree.add(ele);
        }
        return all_tree;
    }
}

```
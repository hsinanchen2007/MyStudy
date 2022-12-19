![2020-03-22_13-10.png](https://pic.leetcode-cn.com/a13825fb60a21cd2a0871f593fa64af9ce314e0ee94c71d1555b72a46a747ee7-2020-03-22_13-10.png)
### 解题思路
`题意`：返回的遍历结果是从叶结点开始按层级返回,也就是`自底向上`保存每个层级遍利结果，
`名词解释`:内嵌列表，即放置当前层级元素的数组；外围列表，即放置所有内嵌数组的数组。
`思路`:人为使用数组实现FILO(先入后出)堆结构。每次遍利完当前层级，直接将内嵌列表放置在 `外围`列表头部(索引为0的位置)，之后的每一层都往头部放置，上一次放的列表就会下沉，即索引值++。整体看结果，`根所在的层级在最下层，叶子所在层级是最上层`，符合题意

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
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        //为空树，返回空列表
        if(root ==null) return new ArrayList<>();
        //存放每层内嵌列表
        List<List<Integer>> levels = new ArrayList<>();
        LinkedList<TreeNode> queue = new LinkedList<>();

        queue.add(root);
        while (!queue.isEmpty()) {
            //每层用一个空列表存 每层的元素
            ArrayList<Integer> level = new ArrayList<>();

            //遍历当前层级
            int len = queue.size();
            for (int i = 0; i < len; i++) {
                TreeNode cur_node = queue.remove();
                level.add(cur_node.val);

                //将当前层级左右子结点存入队列，供下一层级遍历
                //左子树
                if (cur_node.left!=null) queue.addLast(cur_node.left);
                //右子树
                if(cur_node.right!=null) queue.addLast(cur_node.right);
            }
            //遍历完当前层级，直接添加在外围列表首部(索引为0的位置)，
            //最终结果首部是叶子所在层，尾部是根所在层
            levels.add(0,level);
        }
        return levels;
    

    }
}
```
### 解题思路
原本自己写了一个，但是效率偏低，后面看解题有一个大佬借助set写了一个非常优美的解法，
因为没有注释有些遗憾，我就也使用set重写写一个思路一样的，顺便补上注释
@Java-DFS(2ms, beat 97.99%)



本题也是利用的递归，但是巧妙地将需要删除的内容添加到set中，利用set快速匹配的方式快速筛选要删除的节点
在递归的时候仅仅需要遍历整棵树一遍即可完成删点成林，时间复杂度 优异

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

    List<TreeNode> res;
    HashSet<Integer> set;

    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        /*
        *首先定义一个哈希set，用来放所有想要删掉的值
        *好处：回头在递归的时候可以只遍历整棵树一遍就完成删点成林
        */
        set = new HashSet<>();
        for(int eachNum : to_delete) {
            set.add(eachNum);
        }

        res = new LinkedList<>();

        //这里传入的 needAdd 的值为true。意思是：接下来传入的点 有可能 被添加到最终结果res中
        helper(root, true);
        return res;
    }
    /*
    *这个helper函数很有意思，需要解释一下，只要明白这个函数的返回值，参数什么意思就理解了大半
    * @return:返回值可以判断这个 传入的点 是不是需要删除的点
    * @param needAdd :该参数判断这个 点 是否应该被 加入 最终结果内
    */
    private boolean helper(TreeNode node, boolean needAdd) {
        if(node == null) return false;

        //注意，如果set中有node.val的话，那么就意味着这个点需要删除
        if(set.contains(node.val)) {

            //这里依旧是传入参数 needAdd 为 true，意思同上：
            //接下来这个传入的节点 又可能 被添加入最终结果res中
            if(helper(node.left, true)) node.left = null;
            if(helper(node.right, true)) node.right = null;

            //直接返回，不做后续处理了，直接返回true，意思是这个点应该被删除
            return true;
        }

        //如果这个点是 期望中 需要添加的点，将之加入结果的线性表中
        if(needAdd == true) res.add(node);

        /*
        *仔细看,这里的needAdd是传入的false，意思是:下一个点 肯定 不会被加入最终结果res中
        *这里的 if 判断也有意思，如果判断通过的话 
        *意思是: helper 返回了true，即，这个helper传入的点需要删除
        *既然这个传入的点需要被删除，那么就从这里断开：node.left = null;  or  node.right = null;
        */
        if(helper(node.left, false)) node.left = null;
        if(helper(node.right, false)) node.right = null;
        return false;
    }
}
```
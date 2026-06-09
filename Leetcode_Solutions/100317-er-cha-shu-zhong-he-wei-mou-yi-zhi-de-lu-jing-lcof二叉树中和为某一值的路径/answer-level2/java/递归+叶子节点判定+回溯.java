### 解题思路
此处撰写解题思路
首先弄清楚叶子节点含义：左、右孩子节点都是null，searchAllPath得到所有的路径，注意每次加入到res的时候，temp需要重新构建，不然会对同一个对象操作
出口；
当遇到叶子节点时，如果累计和nowSum等于sum就把temp（temp要重新构造）加入res
null节点直接返回
回溯：
当前节点的左右子树都试过后，nowSum减去当前节点的值，temp删除当前节点值（也就是最后一个值）
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
    private List<List<Integer>> res = new LinkedList<>();
    private List<Integer> temp = new LinkedList<>();
    private int sum;
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        this.sum = sum;
        searchAllPath(root, 0);
        return res;
    }
    //叶子节点：左、右孩子都是null
    public void searchAllPath(TreeNode root, int nowSum){ 

        if(root == null){
            return;
        }
        nowSum += root.val;
        temp.add(root.val);
        //叶子节点
        if(root.left == null && root.right == null){
            if(nowSum == sum){
                res.add(new LinkedList(temp));
            }
            nowSum -= root.val;
            temp.remove(temp.size()-1);
            return;
        }
        searchAllPath(root.left, nowSum);
        searchAllPath(root.right, nowSum);
        //回溯，累计和减去当前val，temp删除最后一个值
        nowSum -= root.val;
        temp.remove(temp.size()-1);
    }
}
```
### 解题思路
这个题可以参考从上到下打印二叉树||[](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/)
跟这个方法基本一样，思路差不多，递归遍历整棵数，将每个节点的值添加到对应的集合中
因为要求之字形打印，所以最后将得到的集合中偶数行使用Collections.reverse()翻转即可，也可以在递归函数内部通过判断传入的层数选择从末尾添加还是从头添加，代码如下，关键部分有加注释
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
    List<List<Integer>> list = new ArrayList<List<Integer>>();
    public List<List<Integer>> levelOrder(TreeNode root) {
        if(root==null)return list;
        levelOrder(root,0);
        /*for(int i=0;i<list.size();i++){
            if(i%2==1){
                Collections.reverse(list.get(i));
            }
        }*/
        return list;
    }
    public void levelOrder(TreeNode root,int h){
        //当h与list长度相等时，此时进入了新的一层需要创建一个对应的集合
        if(list.size()==h)list.add(new ArrayList());
        if(h%2==0){
            //从末尾添加
            list.get(h).add(root.val);
        }else{
            //从头部添加
            list.get(h).add(0,root.val);
        }
        //递归查找每一个结点
        if(root.left!=null)levelOrder(root.left,h+1);
        if(root.right!=null)levelOrder(root.right,h+1);
    }
}
```
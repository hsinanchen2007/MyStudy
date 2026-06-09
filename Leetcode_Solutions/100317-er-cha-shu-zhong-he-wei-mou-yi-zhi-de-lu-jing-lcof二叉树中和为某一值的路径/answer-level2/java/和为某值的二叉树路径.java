### 解题思路1.利用先序遍历二叉树方法，一个链表暂存路径，
2.每换一条路径，加入一个节点，就会有一个删除节点的remove执行。


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
    private List<List<Integer>> lists=new ArrayList<>();
    private List<Integer> list=new ArrayList<>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        pathS(root,sum);
        return lists;
    }
    private void pathS(TreeNode root,int tempSum){
        if(root==null) return;
        list.add(root.val);
        tempSum-=root.val;
        if(root.left==null&&root.right==null&&tempSum==0){
            lists.add(new ArrayList(list));
            list.remove(list.size()-1);
            return;
        }
        pathS(root.left,tempSum);
        pathS(root.right,tempSum);
        list.remove(list.size()-1);


    }

}
```
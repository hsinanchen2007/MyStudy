### 解题思路
1、线遍历二叉树，因为值各不相同，所以把它的值放到一个list里面，然后排序
2、遍历排序后的list，从大到小分别计算每个值对应的大于它和它自身的值的累加和，node值为键累加和为value，放到一个map中
3、遍历二叉树，根据map修改每个节点的值


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
    public TreeNode bstToGst(TreeNode root) {
        if(root==null){
            return root;
        }
        List<Integer> values=new ArrayList();
        //遍历二叉树，记录所有节点的值
        search(root,values);
        //排序
        Collections.sort(values);
        Map<Integer,Integer> sumMap=new HashMap();
        //计算累加和
        for(int i=values.size()-1;i>=0;i--){
            if(i==values.size()-1){
                sumMap.put(values.get(i),values.get(i));
            }else{
                sumMap.put(values.get(i),values.get(i)+sumMap.get(values.get(i+1)));
            }
        }
        //修改节点的值
        helper(root,sumMap);
        return root;
    }

    private void search(TreeNode root,List<Integer> values){
        if(root==null){
            return;
        }
        values.add(root.val);
        search(root.left,values);
        search(root.right,values);
    }
    private void helper(TreeNode root,Map<Integer,Integer> sumMap){
        if(root==null){
            return;
        }
        root.val=sumMap.getOrDefault(root.val,0);
        helper(root.left,sumMap);
        helper(root.right,sumMap);
    }
}
```
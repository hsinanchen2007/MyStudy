### 解题思路
官方思想
注意：由于level是从0开始计算的，判断奇偶层需要注意
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
    private List<List<Integer>> list = new ArrayList<List<Integer>>();
    public List<List<Integer>> levelOrder(TreeNode root) {
if(root==null){
    return list;
}
Stack<TreeNode> oddStack = new Stack<>();
Stack<TreeNode> evenStack =  new Stack<>();
int level=0;
oddStack.push(root);
while(!(oddStack.isEmpty()&&evenStack.isEmpty())){
      
      list.add(new ArrayList<Integer>());
       if(level%2==0){
            int oddlength=oddStack.size();
            for(int i=0;i<oddlength;i++){
                            TreeNode oddtree=  oddStack.pop();
                list.get(level).add(oddtree.val);
            if(oddtree.left != null) evenStack.push(oddtree.left);
            if(oddtree.right !=  null) evenStack.push(oddtree.right);

            }
           
       }else{
           // 层数从0开始）偶数层 先添加右结点再添加左结点
         int evelength=evenStack.size();
    
            for(int j=0;j<evelength;j++){
                            TreeNode eventree=  evenStack.pop();
                list.get(level).add(eventree.val);
               
                if(eventree.right!=null) oddStack.push(eventree.right);
                 if(eventree.left!=null) oddStack.push(eventree.left);
            }
       }
 level++;
     }



return list;


}

}
```
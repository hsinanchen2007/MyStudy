![image.png](https://pic.leetcode-cn.com/cda9ff57d06843ce8af53cf887a90f64ff5413d6ba83229e6b7ce858818231ac-image.png)
```
class Solution {
    List<List<Integer>> result = new ArrayList<List<Integer>>();
    private int target;
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        this.target = sum;
        helper(root, 0, new ArrayList<Integer>() );
        return result;
    }
    
    private void helper(TreeNode node, int currentSum, List<Integer> currentList) {
        
        if( node == null ) {
            return ;
        }
        currentSum += node.val;
        currentList.add(node.val);           
        if( node.left == null && node.right == null ) {
            if( currentSum == target ) {              
                result.add( new ArrayList<Integer>(currentList) );
            }
            currentList.remove(currentList.size()-1);
            return ;
        }
        helper(node.left, currentSum, currentList);
        helper(node.right, currentSum, currentList);
        currentList.remove(currentList.size()-1);           
    }  
}
```

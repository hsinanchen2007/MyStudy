### 解题思路
分治思想下，当前节点满足目标和的路径=左右节点满足（目标和-root.val)的所有路径，在此基础上每个路径添加当前节点

### 代码

```java
import java.util.ArrayList;
import java.util.List;


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
        //       5
        //      / \
        //     4   8
        //    /   / \
        //   11  13  4
        //  /  \    / \
        // 7    2  5   1

class Solution {
	public List<List<Integer>> pathSum(TreeNode root, int sum) {
		if(root==null) return new ArrayList<>();		
		List<List<Integer>> re=new ArrayList<>();		
    	
    	if(root!=null&&root.left==null&&root.right==null) {
    		if(root.val==sum) {
    			List<Integer> path=new ArrayList<Integer>();
    			path.add(root.val);
    			re.add(path);
    			return re;
    		}
    	}
    	//分治思想
    	List<List<Integer>> leftList=pathSum(root.left, sum-root.val);
    	List<List<Integer>> rightList=pathSum(root.right, sum-root.val);
    	for(List<Integer> path:rightList) {
    		leftList.add(path);
    	}
    	for(List<Integer> path:leftList) {
    		path.add(0, root.val);
    	}
    	
    	return leftList;
    	
    	
    }

}
```
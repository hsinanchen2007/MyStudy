执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
99.90%
的用户
内存消耗 :
37.6 MB
, 在所有 Java 提交中击败了
88.33%
的用户
```
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
      
	   Map<String,List<TreeNode>> map = new HashMap<>();
	    public List<TreeNode> generateTrees(int n) {
	    	if(n==0){
                List<TreeNode> res = new ArrayList<>();
                return res;
            }
	       
	        return get(1,n);
	        
	        
	    }
	    private List<TreeNode> get(int start, int end){
            String key = start+"-"+end;
	    	if(map.get(key)!=null){
                return map.get(key);
            }
	    	List<TreeNode> list = new ArrayList<TreeNode>();
            if(start>end){
                list.add(null);
                return list;
            }
	    	for(int i=start; i<=end; i++) {
	    		
	    		List<TreeNode> left = get(start,i-1);
	    		List<TreeNode> right = get(i+1,end);
	    		for(TreeNode tn:left) {
	    			for(TreeNode tn1:right) {
		    			TreeNode node = new TreeNode(i);
		    			node.left =tn;
		    			node.right=tn1;
		    			list.add(node);
		    		}
	    		}
	    	}
            map.put(key,list);
	    	return list;
	    }
	    
}
```

### 解题思路
是叶子节点则直接返回

在不是叶子节点的情况下，，
偶数节点--左儿子存在-->将左侧孙子值加上(如果存在)， 进入左儿子的判断
	    -右儿子存在-->将右侧孙子值加上(如果存在)， 进入右儿子的判断
奇数节点-- 左儿子存在-->直接入左儿子判断
       -- 右儿子存在-->直接入右儿子判断

直至判断到为叶子节点，依次返回到父节点,若无右儿子节点需要判断 或 右儿子已判断完成，则继续向上返回，直至对根节点的儿子节点遍历结束，全部返回完成。

下来时 --持续左下
回去时 --右有则走右(继续下来时))，没有则直接回去

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
	
	int sum = 0;
	
    public int sumEvenGrandparent(TreeNode root) {
    	if(root == null)
    		return 0;
    	
        getSum(root);
    	return sum;
    }
    
    public void getSum(TreeNode root) {
    	
    	if(root.left==null&&root.right==null)
    		return  ;

    	//以下---存在儿子节点

    	if(root.val % 2==0)//偶数节点
    	{
    		
    			if(root.left != null) //左儿子存在
    			{
    				
    				if(root.left.left!=null)   //直接去取孙子的值
    					
    					sum+=root.left.left.val;
    					
    				if(root.left.right!=null)
    					sum+=root.left.right.val;
    				
    				//判断左儿子是否符合条件
    				getSum(root.left);
    			}
    				
    			if(root.right != null)//右儿子存在
    			{
    				
    				if(root.right.left!=null)   //直接去取孙子的值
    					sum+=root.right.left.val;
    				if(root.right.right!=null)
    					sum+=root.right.right.val;
    				
    				//判断右儿子是否符合条件
    				getSum(root.right);
    			}
    			
    			
    		
    		
    	}//偶数节点 - 结束
    	else {//奇数节点 - 如果有孩子则继续判断
    		if(root.left!=null)
    			getSum(root.left);
    		if(root.right!=null)
    			getSum(root.right);
    		
    	}
    	

		return;//函数的自动结束  没有 使用return 返回的速度快，增加return 可以使调用更快的返回
//建议使用return,返回路径相同但速度明显更快
    }
    
}

```
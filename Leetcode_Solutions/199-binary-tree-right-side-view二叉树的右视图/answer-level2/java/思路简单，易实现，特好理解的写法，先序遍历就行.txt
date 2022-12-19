





做个标准的先序遍历，加上Map表，及时更新当前已搜索过的结点的对于某层最右边的结点



class Solution {
   List<Integer> res=new ArrayList<>();
	Map<Integer,Integer> map=new HashMap<>();
	int depth=0;
public List<Integer> rightSideView(TreeNode root) {
	//先序遍历，Map存储当前已搜索过的某层的最右边的结点
	//深度优先搜索;
	if(root==null) return res;
	map.put(0, root.val);
	dfs(1,root.left);
	dfs(1,root.right);
    for(int i=0;i<=depth;i++)
    	res.add(map.get(i));
    return res;
    }
public void dfs(int h,TreeNode root) {
	if(root==null) return ;	
	if(h>depth) depth=h;
	map.put(h, root.val);
	dfs(h+1,root.left);
	dfs(h+1,root.right);
}
}
【题目】:二叉树所有到达叶子节点的路径。

【思路】:本题考查的是树的搜索(深度优先/广度优先)+字符串处理。

这里使用深度优先即可。其思路为每次递归时，传入当前的字符串情况，拼接上当前节点，如果到终点就传入代表结果的list。

具体代码见下：

![image.png](https://pic.leetcode-cn.com/5cf8a3ef44f1fe6b3c39ce3de5bf5e4e198e137b0e777f46b979c8b07e1909ed-image.png)


```
public static List<String> binaryTreePaths(TreeNode root) {
		List<String> routes=new ArrayList<String>();
		fun(root,routes,"");
		return (routes);
	}
	
	
	public static void fun(TreeNode root,List<String> routes,String str){
		if(root!=null) {
            
			if(str=="") str+=root.val;//根节点时,前面没有"->"
            
			else str+="->"+root.val;//非根节点,有"->""
			if(root.left==null&&root.right==null)//到达叶子节点，填入routes
				routes.add(str);
			fun(root.left,routes,str);//遍历左子树
			fun(root.right,routes,str);//遍历右子树
		}		
	}
```

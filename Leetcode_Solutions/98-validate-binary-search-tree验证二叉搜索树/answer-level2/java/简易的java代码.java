### 代码

```java
class Solution {
    List<Integer> list = new ArrayList<>();
	public boolean isValidBST(TreeNode root){
		// 中序遍历二叉树，然后扫描结果数组检查其是否升序排列
		if(root == null || (root.left == null && root.right == null)){
			return true;
		}
		// 树中至少有两个结点
		bfs(root.left);
		list.add(root.val);
		bfs(root.right);
		int lastNum = list.get(0);
		for(int i=1;i<list.size();i++){
			int currNum = list.get(i);
			if(currNum <= lastNum){
				return false;
			}
			lastNum = currNum;
		}
		return true;
	}
		
	
	public void bfs(TreeNode node){
		if(node != null){
			// 递归以实现中序遍历
			bfs(node.left);
			list.add(node.val);
			bfs(node.right);
		}
	}
}
```

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/4965530bd01bbd8871689044fa0ded925f8b5c94e71fd8c096b5156160b7a74f-wechat.png)

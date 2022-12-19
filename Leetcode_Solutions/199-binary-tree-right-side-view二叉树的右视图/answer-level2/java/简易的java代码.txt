### 代码

```java
class Solution {
    public List<Integer> rightSideView(TreeNode root){
		List<Integer> res = new ArrayList<>();
		if(root == null){
			return res;
		}
		List<TreeNode> curr = new ArrayList<>();
		curr.add(root);
		while(curr.size()!=0){
			int size = curr.size();
			int val = curr.get(size-1).val;
			res.add(val);
			curr = getNextLayer(curr);
		}
		return res;
	}
	
	public List<TreeNode> getNextLayer(List<TreeNode> curr){
		// 层次遍历
		List<TreeNode> next = new ArrayList<>();
		for(int i=0;i<curr.size();i++){
			TreeNode left = curr.get(i).left;
			TreeNode right = curr.get(i).right;
			if(left!=null){
				next.add(left);
			}
			if(right!=null){
				next.add(right);
			}
			}
		return next;
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/ab328f1c468ae140f37b3811e9cf159b93ccf5de76c79ea234cc0ca110f60e49-1.png)

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/4acd670a26576ae64e1b03a1ab2dae46749c5b6b55f37541a049f864e45836a2-wechat.png)


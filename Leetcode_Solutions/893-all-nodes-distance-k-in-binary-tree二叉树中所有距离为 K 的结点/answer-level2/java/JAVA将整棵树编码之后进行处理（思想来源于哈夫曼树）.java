
## 一种感觉普遍化的思路

1. 首先将整棵树编码，当其向左时记为1，向右时记为3，根节点为1
	例如 root->left->left 为 111,root->right->left->right 为 1313
2. 于是距离可以转化为，两个编码去掉相同前缀时剩下的位数和
	例如111 到 131 的距离为 3（111的位数） + 4（1313的位数） - 2（两次重复） * 1（只有最高位1相同） = 5

## 编码树！！！

```
    class Solution {
		Map<Integer,Long> map = new HashMap<>();
		public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
			List<Integer> list = new ArrayList<>();
			codeTree(root,1);
			long targetCode = 0;
	    
			for(Integer key:map.keySet()) {
				if(key==target.val) {
					targetCode = map.get(key);
    				break;
				}
			}
			for(Integer key:map.keySet()) {
				if(distanceCode(map.get(key),targetCode)==K) {
					list.add(key);
				}
			}
		return list;
	}
	public void codeTree(TreeNode root, long value){
		if(root==null) return;
		map.put(root.val, value);
		codeTree(root.right, value*10+1);
		codeTree(root.left, value*10+3);
	}
	
	public int distanceCode (long val, long target) {
		long sameL = 0;
		long more = Math.max(val, target);
		long less = Math.min(val, target);
	
		long L1 =(long)Math.log10(more)+1;
		long L2 =(long)Math.log10(less)+1;
	    
		double temp = Math.abs(less*(Math.pow(10, L1 - L2)) - more);
		
		sameL = (temp==0)?L1:L1 - (long)(Math.log10(temp+1)) - 1;
	    
		return (int)(L1 + L2 - 2*sameL);
	}
	}
```


因为要判断父子关系，兄弟关系，以及他们之间相隔的代数。考虑对其编码，子节点继承父节点的编码再区分左右新增，由于数字编码比字符串编码快，考虑数字编码时因为是二叉树可以考虑二进制。

![image.png](https://pic.leetcode-cn.com/02f17834a6d42b8c50e39570bdf872dbddb6f3faf5b589b1c5d71cc735c69732-image.png)


如图 110 和 111 ; 110和1 节点的距离都是2，设两个节点的编码为x,y 则其距离为两个编码去掉最长公共前缀时剩下的位数和。衍生出一个判断二进制数最长公共前缀的问题。采用位运算即可。

```
    List<Integer> tmp = new ArrayList<>();
	List<Integer> value = new ArrayList<>();
	int targetValue = 1;

	public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
		find(root, 1, target.val);

		List<Integer> res = new ArrayList<>();
		for (int i=0; i<tmp.size(); i++) {
			if(dis(tmp.get(i), targetValue, K)) {
				res.add(value.get(i));
			}
		}
		return res;
	}
	
	private boolean dis(int x, int y, int K) {
		int max = Math.max(x, y);
		int min = Math.min(x, y);
		
		int maxlen = 0;
		while(max > 0) {
			max >>= 1;
			maxlen++;
		}
		
		int minlen = 0;
		while(min > 0) {
			min >>= 1;
			minlen++;
		}
		
		max = Math.max(x, y);
		min = Math.min(x, y);
		
		max >>= (maxlen - minlen);
		
		int samelen = 0;
		while(max > 0) {
			samelen = ((max & 1) == (min & 1)) ? samelen+1 : 0;
			max >>= 1;
			min >>= 1;
		}
		
		return K == ((maxlen - samelen) + (minlen - samelen));
	}

	private void find(TreeNode node, int n, int target) {
		if (node == null)
			return;

		if (target == node.val) {
			targetValue = n;
		}
		tmp.add(n);
		value.add(node.val);
		if (node.left != null)
			find(node.left, n * 2, target);

		if (node.right != null)
			find(node.right, n * 2 + 1, target);

		return;
	}
```


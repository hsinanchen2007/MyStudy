![image.png](https://pic.leetcode-cn.com/5e6ceb1113e4839e777b4f197972900659d1d62f8cf6c8ed6306cc6bf353aa6a-image.png)
思路：
1.创建min和secondmin两个全局变量
2.遍历整棵树，一直比较min和当前节点的值，获得整棵树的最小值
3.但是这样并不能获得第二小的值，所以我用if语句更新secondmin值，如果root.val > min && root.val <= semin那么就更新它
4.麻烦的是如果[2,2,2]，secondmin的if语句不会执行，这里创建一个count的全局变量，如果count == 0，那么就说明都是节点值都一样，那么返回-1
```
	static int min;
	static int secondmin;
	static int count;
	public static void get(TreeNode root) {
		if (root == null) return;
		if (root.val < min) {
			secondmin = min;
			min = root.val;
		}
		if (root.val > min && root.val <= secondmin) {
			secondmin = root.val;
			count++;
		}
		get(root.left);
		get(root.right);
	}
	
	public int findSecondMinimumValue(TreeNode root) {
			min = Integer.MAX_VALUE;
			secondmin = Integer.MAX_VALUE;
			count = 0;
	        if (root == null) return -1;
	        get(root);
	        if (min == secondmin) return -1;
			if (count == 0) return -1;
	        else return secondmin;
	}
```

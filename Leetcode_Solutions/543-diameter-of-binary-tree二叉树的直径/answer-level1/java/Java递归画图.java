题目的要求是寻找最大的直径

最大的直径包括什么呢：1、有根节点的路径
                    2、不包括根节点的路径
第一种情况是最容易想到的
![无标题.png](https://pic.leetcode-cn.com/f2d7389b55970ed1040a1329cda9ff8e7b31dc84e41dd8e040e84cd4e9f19109-%E6%97%A0%E6%A0%87%E9%A2%98.png)


如图所示，经过根节点的时候 计算左右两边的子树即可，所以我们可以在递归时给予每一个子节点一个1值。每次递归相加left  相加right
当遇到两个子节点都有值时，直接取max(left,right)，因为题目要求的是最大路径，不需要考虑另外一种较小的情况
 但是对于第二种情况，当遇到不取根节点的时候呢
如
![\]\]P{)44MMOO776XYG6NMVF8.png](https://pic.leetcode-cn.com/8b5bf871a54d31b63e3b016e8521545a6a31ba2f09c77e61bfb7b0dcd71a4ae3-%5D%5DP%7B\)44MMOO776XYG6NMVF8.png)

这种情况下，不是根节点的值是最大值的时候
只需要设置一个存储的最大值
在每个节点递归后，用当前节点子节点路径值,即left+right比较即可

```
class Solution {
int result=Integer.MIN_VALUE;//设定最小值 记录当前最长路径
	int back(TreeNode root) {
		if(root==null) {return 0;}//后序遍历遇到空时 返回0代表当前路径计数为0
		int left=0;
		int right=0;
		left=left+back(root.left);//记录当前节点左边的路径和
        right=right+back(root.right);//记录当前节点右边的路径和
        result=Math.max(result, left+right);//和记录中的最大路径 比较 更新
		return Math.max(left, right)+1;//如果左右节点都不是空 那么就回到左右路径的最大值 供上一个节点记录
	}
	   public int diameterOfBinaryTree(TreeNode root) {
           if(root==null) {return 0;}
	        back(root);
	        return result;
       }}
```
	
	    

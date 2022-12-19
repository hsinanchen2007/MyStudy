## 654. 最大二叉树
[原题链接](https://leetcode-cn.com/problems/maximum-binary-tree/submissions/)
给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：

二叉树的根是数组中的最大元素。
左子树是通过数组中最大值左边部分构造出的最大二叉树。
右子树是通过数组中最大值右边部分构造出的最大二叉树。
通过给定的数组构建最大二叉树，并且输出这个树的根节点。

**示例 ：**
```java
输入：[3,2,1,6,0,5]
输出：返回下面这棵树的根节点：

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
```
**提示：**
1. 给定的数组的大小在 [1, 1000] 之间。

### 要点
将数组分割成左、右两边，各自生成一棵最大二叉树之后，拼接到根结点。
### 解法1
建议你可以先学习 <u> [【LeetCode算法修炼+动画演示】—— 998. 最大二叉树 II](https://blog.csdn.net/weixin_42322309/article/details/104241690)，这道题给出了一个在尾部插入节点的方法。</u>
#### 代码片段 - 1
尾部插入法
```java
public TreeNode constructMaximumBinaryTree2(int[] nums) {
	if (nums == null || nums.length == 0) {//1.数组错误直接返回。
		return null;
	}
	ChangeNode changeNode = new ChangeNode();
	TreeNode head = new TreeNode(nums[0]);//2.创建第一个节点的树
	for (int i = 1; i < nums.length; i++) {
		head = changeNode.insertIntoMaxTree(head, nums[i]);//3.循环插入节点。
	}
	return head;//4.返回结果。
}
```
### 解法2
递归创建树。
#### 代码片段 - 2
```java
public TreeNode constructMaximumBinaryTree(int[] nums) {
	if (nums == null || nums.length == 0) {//1.数组错误直接返回。
		return null;
	}
	return constructMaximumBinaryTreeH(nums, 0, nums.length);//2.递归创建树，注意这里开始、结束的区间[0...nums.length)
}
public TreeNode constructMaximumBinaryTreeH(int[] nums, int start, int end) {
	if (start >= end) {//3.由传入的区间得知右边是开区间，不包含该数。也就是说［1...1)这个区间直接返回。
		return null;
	}

	int maxVal = 0; //4.找到一个最大值所在的位置。
	int maxI = start;
	for (int i = start; i < end; i++) {
		if (nums[i] > maxVal) {
			maxVal = nums[i];
			maxI = i;
		}
	}

	TreeNode node = new TreeNode(nums[maxI]);//5.创建根结点。
	node.left = constructMaximumBinaryTreeH(nums, start, maxI);//6.创建左边节点
	node.right = constructMaximumBinaryTreeH(nums, maxI + 1, end);//7.创建右边结点。
	return node;
}
```
### 评论区问题答疑
---
## 结尾 
##### <u>[1.博客地址](https://blog.csdn.net/weixin_42322309)</u>
##### <u>[2.源代码仓库](https://gitee.com/Gre-Z/Algorithm")</u>
> 如果你在代码里看到了用 数字标记的注释 如 //1.xxx 这是我写代码的顺序，希望能给你一点启发。
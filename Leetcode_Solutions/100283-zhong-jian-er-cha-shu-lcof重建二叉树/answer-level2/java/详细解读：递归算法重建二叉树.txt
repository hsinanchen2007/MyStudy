### 写在前面

前序遍历序列结合中序遍历序列可以唯一确定一颗二叉树，具体实现步骤：
1、如果中序序列（子序列）起始下标大于结束下标则返回null，表示没有子节点了，否则进行下一步
2、根据前序序列中当前位置的值创建一个节点，并且该位置作为中序序列的切割点
3、在切割后的序列中找到与当前节点等值的节点，然后前序序列中当前位置后移一位
4、按照前面的步骤递归处理切割点左边部分的序列，将返回的节点作为当前节点的左子节点。右子节点同理
5、返回当前节点

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        /*
		 * 创建只有一个元素的数组，该元素的值指向前序序列的元素，之所以用数组，是为了
		 * 能让通过引用让递归函数都能访问到，保证preorder数组不重复遍历
		 */
		int[] current = {0}; 
		return build(current, 0, inorder.length-1,preorder, inorder);
    }

    /**
	 * @param current：存放着一个记录当前遍历到前序序列的位置的元素
	 * @param start：切割后得到的序列的起始位置下标
	 * @param end：切割后得到的序列的结束位置下标
	 * @param preorder：前序序列
	 * @param inorder：中序序列
	 * @return：返回当前节点
	 */
    private TreeNode build(int[] current, int start, int end, int[] preorder, int[] inorder) {
		if(start > end) return null; //如果起始下标大于结束下标则返回null，表示没有子节点了
		TreeNode node = new TreeNode(preorder[current[0]]); //根据当前前序序列中的值创建一个节点
		int j= start;
		for(;j<=end;j++) {
			//如果切割后的序列中找到与当前节点等值的节点才跳出循环
			if(inorder[j] == preorder[current[0]]) break; 
		}
		current[0]++; //前序序列中当前所在位置后移一位，进行下面的递归函数
		node.left = build(current, start, j-1, preorder, inorder);
		node.right = build(current, j+1, end, preorder, inorder);
		return node;
	}
}
```
### 解题思路
- 二叉搜索树后序遍历结果最后一个是根节点
- 左半部分的值应该小于根节点
- 右半部分应该大于根节点
- 左半部分部分和右半部分也要满足二叉搜索树

### 代码

```java
class Solution {
   public boolean verifyPostorder(int[] postorder) {
		if (postorder == null || postorder.length == 0)
			return true;
		return doverifyPostorder(postorder, 0, postorder.length - 1);
	}

	private boolean doverifyPostorder(int[] postorder, int start, int end) {
		int root=postorder[end];
		int i=start;
		for(;i<end;i++) {
			if(postorder[i]>root)break;
		}
		for(int j=i;j<end;j++) {
			if(postorder[j]<root)return false;
		}
		boolean left=true;
		if(i>start) {
			left=doverifyPostorder(postorder, start, i-1);
		}
		boolean right=true;
		if(i<end-1) {
			right=doverifyPostorder(postorder, i, end-1);
		}
		return left&&right;
	}
}
```
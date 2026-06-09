# 108. 将有序数组转换为二叉搜索树（C语言 递归）
题目中测试用例[-10,-3,0,5,9]生成的平衡二叉树应为：

![image.png](https://pic.leetcode-cn.com/22bab7ba26b001c86f710df62e53ca6e7e59da0ce42f4647a8a6a8c1ff48e2d7-image.png)

以上面的测试用例为例，数组值nums为[-10,-3,0,5,9]，数组numsSize长度5。
平衡二叉树的根节点应该是这组数据中大小中间的值 0.
由于测试用例是一个有序数组，所以平衡二叉树的根节点的值就应该为数组中坐标中点(numsSize/2)的值。

那么:
该根节点的左节点值 应该为位于数组的范围就为[0 ~ (numsSize/2) -1]的中间值。
该根节点的右节点值 应该为位于数组的范围就为[(numsSize/2)+1 ~ numsSize]的中间值。

这样可以通过数组范围left,right和数组nums生成递归。

```
void InitNode(struct TreeNode *nowNode){
	nowNode->left  = NULL;
	nowNode->right = NULL;
}

struct TreeNode * CreateBST( int* nums , int left , int right ){
	if(left > right){
		return NULL;
	}
	
	struct TreeNode *NowNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	InitNode (NowNode);
	
	if( right == left){
		NowNode->val = nums[left];
	}else{
		int nownums = (right + left )/2;
		NowNode->val = nums[nownums];
		
		NowNode->left = CreateBST(nums,left,nownums-1);
		NowNode->right = CreateBST(nums,nownums+1,right);
	}
	return NowNode;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
	return CreateBST(nums,0,numsSize - 1);
}
```


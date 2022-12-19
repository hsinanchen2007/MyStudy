- 第一次中序遍历得到一个数组，数组中存在一组逆序的数
- 从前往后找第一个比前后都大的数，从后往前找第一个比前后都小的数，即为逆序的数，将逆序数交换
- 第二次中序遍历将值回填即可
```
#define NULL_PTR (0)
#define TRUE     (1)
#define FALSE    (0)

#define MAX_SIZE (1000)

/*
二叉搜索树的中序遍历是一个升序序列
其中2个值被错误交换，那么中序遍历的序列中有两个值必然是逆序的，只需要在数组中找到逆序的这两个数，交换，然后再将值进行回填即可。
*/

int g_val[MAX_SIZE];
int g_index = 0;

/*中序遍历二叉树(左根右)，将每一个节点的值保存到链表中*/
void InOrderTraverseGetVal(struct TreeNode *treeNode)
{	
	if (treeNode == NULL_PTR) {
		return;
	}
	InOrderTraverseGetVal(treeNode->left);
	/*-----------中序遍历处理--------*/
	g_val[g_index] = treeNode->val;
	g_index++;
	/*------------------------------*/
	InOrderTraverseGetVal(treeNode->right);
}

void InOrderTraverseSetVal(struct TreeNode *treeNode)
{
	if (treeNode == NULL_PTR) {
		return;
	}
	InOrderTraverseSetVal(treeNode->left);
	/*-----------中序遍历处理--------*/
	treeNode->val = g_val[g_index];
	g_index++;
	/*------------------------------*/
	InOrderTraverseSetVal(treeNode->right);
}

/*逆序的数，其中一个比它后面的数大，另一个比它前面的数小*/
void InverseNumber()
{
	int i;
	int low = g_index - 1;
	int high = 0;
	int temp;
	
	/*先找第一个比两边都大的数*/
	for (i = 0; i < g_index; i++) {
		if ((i == 0) && (g_val[i] > g_val[i + 1])) {
			high = i;
			break;
		}
		if ((i > 0) && (i + 1 < g_index) && (g_val[i] > g_val[i - 1]) && (g_val[i] > g_val[i + 1])) {
			high = i;
			break;
		}
	}

	/*从后往前找第一个比两边都小的数*/
	for (i = g_index - 1; i >= 0; i--) {
		if ((i == g_index - 1) && (g_val[i] < g_val[i - 1])) {
			low = i;
			break;
		}
		if ((i > 0) && (i + 1 < g_index) && (g_val[i] < g_val[i - 1]) && (g_val[i] < g_val[i + 1])) {
			low = i;
			break;
		}
	}

	temp = g_val[low];
	g_val[low] = g_val[high];
	g_val[high] = temp;
}

void recoverTree(struct TreeNode* root) {
	g_index = 0;
	InOrderTraverseGetVal(root);
	InverseNumber();
	g_index = 0;
	InOrderTraverseSetVal(root);
}
```

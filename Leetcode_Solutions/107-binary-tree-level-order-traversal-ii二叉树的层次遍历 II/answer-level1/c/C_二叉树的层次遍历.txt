### 解题思路
1.复制并且更新一下树，让树上的每个节点都能记录自己所在的层次
2.层次遍历的顺序，把树节点入队，注意要用队保存树的节点，不要在出队的时候删除节点
3.统计每层的节点数，作为返回数组的每行列数（详细见代码注释）

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 
  //-------------------------树的节点，记录节点所在层
typedef struct NodeOfTree {
	int data;
	struct NodeOfTree* left;
	struct NodeOfTree* right;
	int level;
}NodeOfTree;
//新建一个树的节点
NodeOfTree* newNodeOfTree(int Data, int Level)
{
	NodeOfTree* n = (NodeOfTree*)malloc(sizeof(NodeOfTree));
	n->data = Data;
	n->left = 0;
	n->right = 0;
	n->level = Level;
	return n;
}
//把不能记录节点所在层的旧树跟新成能记录的新树
NodeOfTree* updataTree(struct TreeNode* OldRoot, int Level)
{
	if (OldRoot == 0)
		return 0;
	else
	{
		NodeOfTree* NewRoot = newNodeOfTree(OldRoot->val, Level);
		NewRoot->left = updataTree(OldRoot->left, Level + 1);
		NewRoot->right = updataTree(OldRoot->right, Level + 1);
		return NewRoot;
	}
}
//销毁树
void delTree(NodeOfTree* Root)
{
	if (Root == 0) return;
	delTree(Root->left);
	delTree(Root->right);
	free(Root);
}

//-------------------------链表队列节点
typedef struct NodeOfQueue {
	NodeOfTree* treeNode;
	struct NodeOfQueue* next;
}NodeOfQueue;
//新建节点
NodeOfQueue* newNodeOfQueue(NodeOfTree* Node)
{
	NodeOfQueue* n = (NodeOfQueue*)malloc(sizeof(NodeOfQueue));
	n->treeNode = Node;
	n->next = 0;
	return n;
}
//入队
void pushInQueue(NodeOfQueue** rear, NodeOfTree* Node)
{
	NodeOfQueue* n = newNodeOfQueue(Node);
	n->next = (*rear)->next;
	(*rear)->next = n;
	(*rear) = (*rear)->next;
}
//出队
NodeOfTree* popOutQueue(NodeOfQueue* head, NodeOfQueue* rear)
{

	if (head->next != 0)
	{
		if (head->next == rear)
			rear = head;
		NodeOfQueue* del = head->next;
		head->next = del->next;
		NodeOfTree* n = del->treeNode;
		free(del);
		return n;
	}
	return 0;
}
//记录该层有几个节点
int numsOfNodes(NodeOfQueue* head)
{
	NodeOfQueue* iter = head->next;
	int l = iter == 0 ? 0 : iter->treeNode->level;
	int sum = 0;
	while (iter!=0&&iter->treeNode->level == l)
	{
		++sum;
		iter = iter->next;
	}
	return sum;
}
//销毁队列
void delQueue(NodeOfQueue* head)
{
	while (head != 0)
	{
		NodeOfQueue* del = head;
		head = head->next;
		free(del);
	}
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
	//如果输入了空树，直接返回
    if(root==0)
    {
        *returnSize=0;
        *returnColumnSizes=0;
        return 0; 
    }
	//更新树
	NodeOfTree* newRoot = updataTree(root, 1);
	//建队列
	NodeOfQueue* head = newNodeOfQueue(0);
	NodeOfQueue* rear = head;
	//层次遍历，用iter代替队头标志，防止出队的时候删除节点。层次遍历完，队列里的节点按层次遍历的顺序储存好了
	pushInQueue(&rear, newRoot);
	NodeOfQueue *iter = head->next;
	while (iter != 0)
	{
		if (iter->treeNode->left != 0)
			pushInQueue(&rear, iter->treeNode->left);
		if (iter->treeNode->right != 0)
			pushInQueue(&rear, iter->treeNode->right);
		iter = iter->next;
	}
	//队尾的节点是层次遍历最后入队的，也就是最底层的叶节点。
	//用这个节点的层数初始化返回数组的大小值（行数，树有几层就，返回的数组就有几行）
	//建立返回数组
	*returnSize = rear->treeNode->level;
	*returnColumnSizes = (int*)malloc(sizeof(int)**returnSize);
	int** result = (int **)malloc(sizeof(int*)**returnSize);
	//队头的节点是根节点，返回的数组要从最后一行开始初始化
	for (int i = (*returnSize) - 1; i >= 0; --i)
	{
		//统计一下这层有几个节点，按量初始化对应行的列数
		(*returnColumnSizes)[i] = numsOfNodes(head);
		//在返回的数组对应的行中开辟空间存放数据
		result[i] = (int*)malloc(sizeof(int)*(*returnColumnSizes)[i]);
		//凡是这一层的都存进这行
		int theLevel = head->next->treeNode->level, j = 0;
		while (head->next!=0&&head->next->treeNode->level == theLevel)
		{
			NodeOfTree* n = popOutQueue(head, rear);
			result[i][j++] = n->data;
		}
	}

	delTree(newRoot);
	delQueue(head);
	return result;
}
```
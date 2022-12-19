# 199. 二叉树的右视图
**思路：**
- 题目要求输出二叉树的左视图，实质上是输出层次遍历中每层最右边节点。可以利用队列进行层次遍历。
- 要进行层次的划分，就需要知道当前二叉树节点的层数，需要自定义结构体，在保存原有二叉树节点信息的情况下，保存二叉树节点层数：
```
typedef struct LevelTNode{
	TreeNode* m_TreeNode;
	int m_level;
}LevelTNode;
```
- 建立队列（用于辅助层次遍历）建立结果数组：
```
vector<int> rst;
queue<LevelTNode*> m_queue;
```
- 然后在题目给出二叉树根节点不空的情况下，将根节点入队：
```
//头结点入队
temp = new LevelTNode();
temp->m_TreeNode = root;
temp->m_level = 1;
m_queue.push(temp);
```

- 接下来进行层次遍历，每次从队列中拿出一个层次遍历节点，如果其存在左、右节点，则将其左右节点入队，根据队列先进先出特性，就可以得到完整的层次遍历序列;
- 由于题目答案要求每层最右边的节点值，所有取出节点时要对当前节点和队列进行判断：
    1. 当前节点出队后，队列为空时--该节点为最右侧节点。
    2. 当前节点出队后，队列不空，结当前节点层数与现在对头节点层数不同时--该节点为最右侧节点。
```
while(!m_queue.empty())
{
	temp = m_queue.front();
	m_queue.pop();
				
	if( (m_queue.empty()) || (m_queue.front()->m_level != temp->m_level) )
	{
		rst.push_back(temp->m_TreeNode->val);
	}
				
	//子树入队
	if(temp->m_TreeNode->left != NULL)
	{
		LevelTNode *left = new LevelTNode();
		left->m_TreeNode = temp->m_TreeNode->left;
		left->m_level = temp->m_level+1;
		m_queue.push(left);
	}
	if(temp->m_TreeNode->right != NULL)
	{
		LevelTNode *right = new LevelTNode();
		right->m_TreeNode = temp->m_TreeNode->right;
		right->m_level = temp->m_level+1;
		m_queue.push(right);
	}
}
```
**完整代码：**
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	typedef struct LevelTNode{
		TreeNode* m_TreeNode;
		int m_level;
	}LevelTNode;
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rst;
		queue<LevelTNode*> m_queue;
		LevelTNode *temp;
		
		if(root != NULL)
		{
			//头结点入队
			temp = new LevelTNode();
			temp->m_TreeNode = root;
			temp->m_level = 1;
			m_queue.push(temp);
			
			while(!m_queue.empty())
			{
				temp = m_queue.front();
				m_queue.pop();
				
				if( (m_queue.empty()) || (m_queue.front()->m_level != temp->m_level) )
				{
					rst.push_back(temp->m_TreeNode->val);
				}
				
				//子树入队
				if(temp->m_TreeNode->left != NULL)
				{
					LevelTNode *left = new LevelTNode();
					left->m_TreeNode = temp->m_TreeNode->left;
					left->m_level = temp->m_level+1;
					m_queue.push(left);
				}
				if(temp->m_TreeNode->right != NULL)
				{
					LevelTNode *right = new LevelTNode();
					right->m_TreeNode = temp->m_TreeNode->right;
					right->m_level = temp->m_level+1;
					m_queue.push(right);
				}
			}
		}
		return rst;
    }
};
```


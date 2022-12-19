# 102. 二叉树的层次遍历
**思路：**
这道题的本质是树的层次遍历（广度优先遍历）。
树的层次遍历需要用队列来实现，遵循如下原则：
1. 首先把根节点加入队列。
2. 取出根节点，再查看根节点的左子树是是否存在，存在的话将左子树加入队列。同理，查看根节点的右子树是是否存在，存在的话将右子树加入队列。
3. 继续取出队列中的元素，由于队列先进先出的特性，在队列不空的情况下重复以上过程，就可以完成树的广度优先遍历。

**但是我们无法找到层与层之间元素的分割点。但我们知道层次遍历后所有元素都是按层次排列的。
所以，我们可以自定义一个结构体，在存储树的节点元素的同时，保存树的层数。**
```
        typedef struct m_TreeNode{
		TreeNode* m_Node;
		int m_Level;
	}m_TreeNode;
```

在存入根节点时我们定义该层为1.
```
        m_TreeNode temp;
    	temp.m_Node = root;
    	temp.m_Level = 1;
        m_queue.push(temp);
```
在左右子树入队是，将层数加一，这样我们就可以找到层与层之间的分界点。
```
if( temp.m_Node->left != NULL ) {
    m_TreeNode temp_left;
    temp_left.m_Node  = temp.m_Node->left;
    temp_left.m_Level = temp.m_Level+1;
    m_queue.push(temp_left);
}
```
在判断队列元素层数与当前层不同时，将一维数组元素加入结果二维数组，并清空一维数组元素。
**循环后将最后一层结果过加入结果二维数组。**

最终代码：
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
	typedef struct m_TreeNode{
		TreeNode* m_Node;
		int m_Level;
	}m_TreeNode;

	vector<int> rst_item;		//二维数组中的一维数组元素
	vector<vector<int>> rst;	//结果二维数组
	queue<m_TreeNode> m_queue;	//队列
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    	if(!root)
    		return rst;

    	m_TreeNode temp;
    	temp.m_Node = root;
    	temp.m_Level = 1;
        m_queue.push(temp);

        int t_Level = 1;
        while( !m_queue.empty() ){
        	temp = m_queue.front();
        	if( temp.m_Level != t_Level ) {
        		rst.push_back(rst_item);
        		rst_item.clear();
        		t_Level = temp.m_Level;
        	}

        	rst_item.push_back(temp.m_Node->val);
        	m_queue.pop();

        	if( temp.m_Node->left != NULL ) {
        		m_TreeNode temp_left;
        		temp_left.m_Node  = temp.m_Node->left;
        		temp_left.m_Level = temp.m_Level+1;
        		m_queue.push(temp_left);
        	}
        	if( temp.m_Node->right != NULL ) {
        		m_TreeNode temp_right;
        		temp_right.m_Node  = temp.m_Node->right;
        		temp_right.m_Level = temp.m_Level+1;
        		m_queue.push(temp_right);
        	}
        }
    	rst.push_back(rst_item); //输出最后一层

        return rst;
    }
};
```




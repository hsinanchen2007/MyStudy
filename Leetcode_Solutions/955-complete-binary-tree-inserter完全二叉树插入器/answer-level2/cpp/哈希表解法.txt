### 解题思路
用哈希表，坐标值存相应结点，记录下一个结点插入坐标值，通过回溯表达式 （插入结点坐标值 - 1） / 2得到父结点坐标，哈希表直接取到相应父结点插入即可 

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        m_root = root;
        initDtNode(m_root,0);
        m_nextdt++;
        m_isRight = m_nextdt % 2 == 0 ? true : false;
    }

    void initDtNode(TreeNode* root,int level)
    {
        if (!root)
        {
            return;
        }
        m_dtNode[level] = root;
        initDtNode(root->left,level * 2 + 1);
        initDtNode(root->right,level * 2 + 2);
        m_nextdt = max(m_nextdt,level);
    }
    
    int insert(int v) {
        TreeNode* newNode = new TreeNode(v);
		int parentdt = (m_nextdt - 1) / 2;
		if (m_isRight)
		{
			m_dtNode[parentdt]->right = newNode;
			m_isRight = false;
		}
		else
		{
			m_dtNode[parentdt]->left = newNode;
			m_isRight = true;
		}
		m_dtNode[m_nextdt++] = newNode;
		return m_dtNode[parentdt]->val;
    }
    
    TreeNode* get_root() {
        return m_root;
    }


       

    TreeNode*               m_root;
    unordered_map<int,TreeNode*> m_dtNode;
    int                     m_nextdt;
    bool                    m_isRight;
};


复杂度分析：
时间复杂度：init（o）n ，insert（o）1
空间复杂度：（o）n，n为当前结点数
/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
```
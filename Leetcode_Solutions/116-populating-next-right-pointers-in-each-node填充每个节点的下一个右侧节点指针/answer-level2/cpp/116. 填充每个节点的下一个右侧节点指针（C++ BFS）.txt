# 116. 填充每个节点的下一个右侧节点指针（C++ BFS）
**思路：**
广度优先遍历的变形，把BFS中每层的左边元素与右边元素相连接。
注意：
如果层数改变时的上一个节点（即：上一层最后一个节点）不需要连接。
```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
private:
	typedef struct m_TreeNode{
		Node* m_Node;
		int m_Level;
	}m_TreeNode;
	queue<m_TreeNode> m_queue;
public:
    Node* connect(Node* root) {
    	if(!root)
    		return root;
    	
        m_TreeNode temp;
        temp.m_Node = root;
        temp.m_Level = 1;
        m_queue.push(temp);

        Node* last = NULL;

        int t_Level = 1;
        while( !m_queue.empty() ){
        	temp = m_queue.front();
        	m_queue.pop();

        	if( temp.m_Level != t_Level ){
        		t_Level = temp.m_Level;
        	}else{
        		if( last )

        			last->next = temp.m_Node;
        	}
        	last = temp.m_Node;
        	
        	if( temp.m_Node->left != NULL ){
        		m_TreeNode temp_left;
        		temp_left.m_Node = temp.m_Node->left;
        		temp_left.m_Level = temp.m_Level + 1;
        		m_queue.push(temp_left);
        	}
        	if( temp.m_Node->right != NULL ){
        		m_TreeNode temp_right;
        		temp_right.m_Node = temp.m_Node->right;
        		temp_right.m_Level = temp.m_Level + 1;
        		m_queue.push(temp_right);
        	}
        }
        return root;
    }
};
```

### 解题思路


### 方法1：BFS，每层前后连接

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root==NULL) return root;
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            Node* last=q.front();
            q.pop();
            if(last->left) q.push(last->left);
            if(last->right) q.push(last->right);
            for(int i=1;i<len;i++){
                Node* cur=q.front();
                q.pop();
                last->next=cur;
                last=cur;
                if(last->left) q.push(last->left);
                if(last->right) q.push(last->right);
            }
        }
        return root;
    }
};
```
### 递归DFS，学习自[动画演示+三种实现 ](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/dong-hua-yan-shi-san-chong-shi-xian-116-tian-chong/)
```
class Solution {
public:
    Node* connect(Node* root) {
		dfs(root);
		return root;
	}	
	void dfs(Node* root) {
		if(root==NULL) {
			return;
		}
		Node* left = root->left;
		Node* right = root->right;
		//以root为起点，将整个纵深这段串联起来
		while(left!=NULL) {
			left->next = right;
			left = left->right;
			right = right->left;
		}
		//递归的调用左右节点，完成同样的纵深串联
		dfs(root->left);
		dfs(root->right);
    }
};
```

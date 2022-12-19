### 解题思路
C++ 非递归中序遍历 O(1)空间

### 代码

```cpp
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
      if(root==NULL)
      return NULL;
      Node* head=NULL,* prev=NULL,* cur=root;
      stack<Node *> stack;
      while(cur||!stack.empty())
      {
        while(cur)
        {
          stack.push(cur);
          cur=cur->left;
        }
        cur=stack.top();
        if(prev)
        {
          prev->right=cur;
          cur->left=prev;
        }
        
        if(head==NULL)
          head=cur;
        stack.pop();
		    prev=cur;
        cur=cur->right;
      }
      prev->right=head;
      head->left=prev;
      return head;
    }
};
```
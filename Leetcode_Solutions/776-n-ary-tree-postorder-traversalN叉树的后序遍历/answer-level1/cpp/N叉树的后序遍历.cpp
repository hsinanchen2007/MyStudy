**后序遍历 LRN 可以由 NRL 通过一个栈逆序得到，而NRL类似于先序遍历，只不过先序遍历是从右往左入栈子树，而此处是从左往右入栈子树**
```
class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root == NULL)
            return vector<int>();
        vector<int> vec;
        stack<Node*> stk1,stk2;
        stk1.push(root);
        while(stk1.size()){
            Node *node = stk1.top();
            stk1.pop();
            stk2.push(node);
            for(int i = 0;i < node->children.size();i++){
                stk1.push(node->children[i]);
            }
        }
        while(stk2.size()){
            Node *p = stk2.top();
            stk2.pop();
            vec.push_back(p->val);
        }
        return vec;
    }
# };
```

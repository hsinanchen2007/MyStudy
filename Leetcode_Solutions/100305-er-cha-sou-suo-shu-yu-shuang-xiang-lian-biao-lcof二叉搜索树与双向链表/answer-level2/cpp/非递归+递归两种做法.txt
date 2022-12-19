- 其实做法是类似的
- 非递归做法如下使用中序遍历非递归算法之前先找到第一个和最后一个节点(即最左和最右节点)
- 然后使用中序遍历非递归算法将节点连起来
```c++
class Solution {
public:
    Node* head;
    Node* treeToDoublyList(Node* root) {
        if(!root)return root;
        Node* first = root;
        Node* end = root;
        Node* p = root;
        while(first->left)first = first->left;
        while(end->right)end = end->right;
        head = first;
        stack<Node*>s;
        while(p || !s.empty()){
            if(p){
                s.push(p);
                p = p->left;
            }else{
                p = s.top();
                if(p!=head){            //将中序遍历的节点连接起来
                    first->right = p;
                    p->left = first;
                    first=p;
                }
                s.pop();
                p=p->right;
            }
        }
        head->left = end;
        end->right = head;
        return head;
    }
};
```
- 非递归算法如下
```c++
class Solution {
public:
    Node* head=NULL;
    Node* last=NULL;
    Node* treeToDoublyList(Node* root) {
        if(!root)return root;
        inorder(root);
        head->left = last;      //首尾相连
        last->right = head;
        return head;
    }
    void inorder(Node* root){
        if(!root)return ;
        inorder(root->left);
        if(!last){
            last = root;
            head = root;
        }else{
            last->right = root;
            root->left = last;
            last = root;
        }
        inorder(root->right);
    }
};
```

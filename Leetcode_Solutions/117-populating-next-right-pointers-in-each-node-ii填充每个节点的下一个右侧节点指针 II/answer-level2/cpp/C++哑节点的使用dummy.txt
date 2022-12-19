### 解题思路
使用dummy方便操作

### 代码

```cpp

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        Node* temp=root;
        Node *dummy=new Node();
        while(temp){
            dummy->next=NULL;
            Node *tail=dummy;
            while(temp){
                if(temp->left){
                    tail->next=temp->left;
                    tail=tail->next;
                }
                if(temp->right){
                    tail->next=temp->right;
                    tail=tail->next;
                }
                temp=temp->next;
            }
            temp=dummy->next;
        }
        return root;
    }
};
```
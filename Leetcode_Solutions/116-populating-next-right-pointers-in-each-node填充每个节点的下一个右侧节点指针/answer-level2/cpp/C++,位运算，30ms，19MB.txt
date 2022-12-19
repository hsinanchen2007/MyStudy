### 解题思路
先测出树的层数，然后每层从左到右依次next。left为二进制的0，right为二进制的1。

### 代码

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
        if(root==NULL)
        return root;
        int depth=0;
        Node* temp=root;
        while(temp->left!=NULL){
            depth++;
            temp=temp->left;
        }
        int jinzhi=2;
        for(int i=1;i<=depth;i++){
            for(int j=0;j<jinzhi-1;j++){
                ne(root,j,i)->next=ne(root,j+1,i);
            }
            jinzhi*=2;
        }
        return root;
    }

    Node* ne(Node* root,int a,int n){
        Node* ans=root;
        int c=pow(2,n-1);
        for(int i=0;i<n;i++){
            if(a/c==0)
            ans=ans->left;
            else
            ans=ans->right;
            a=a%c;
            c/=2;
        }
        return ans;
    }  
};
```
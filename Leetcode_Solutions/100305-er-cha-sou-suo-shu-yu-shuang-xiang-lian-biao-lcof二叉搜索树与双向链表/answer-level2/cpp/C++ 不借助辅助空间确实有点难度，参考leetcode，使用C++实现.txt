难点在于如何保存当前节点的前一个节点，这里使用二级指针pLast实现
```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root)
            return root;
        Node* pLast = NULL;
        cout<<"开始"<<endl;
        helper(root, &pLast);
        cout<<"结束"<<endl;

        Node* pHead;
        pHead = pLast;
        while(pHead && pHead->left){
            cout<<pHead->val;
            pHead = pHead->left;   
        }
        pHead->left = pLast;
        pLast->right = pHead;
        return pHead;
    }

    void helper(Node* root, Node** pLast){
        if(!root)
            return; // 空，返回
        Node* pCurrent = root;
        if(pCurrent->left!=NULL)  // 左子树不为空，知道root指向1
            helper(pCurrent->left, pLast);
        pCurrent->left = *pLast;
        if((*pLast)!=NULL)
            (*pLast)->right = pCurrent;
        *pLast = pCurrent;  // 第一次的时候pLast指向了1
        if(pCurrent->right)
            helper(pCurrent->right, pLast);
    }
};
```

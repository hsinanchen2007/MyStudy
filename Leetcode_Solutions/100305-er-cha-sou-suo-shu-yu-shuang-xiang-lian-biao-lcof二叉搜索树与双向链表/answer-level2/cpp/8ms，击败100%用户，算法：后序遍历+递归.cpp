后续遍历：
1、先遍历左子树，返回左子树创建的循环链表；
2、将root和左循环链表merge一起
3、再遍历右子树，返回右子树创建的循环链表；
4、将右子树和前面创建的循环链表merge一起
class Solution {
private:
    //Node* head;
    //Node* tail;
public:
    Node* TransformTreeToList(Node* root) 
    {
        if (root == NULL) {
            return NULL;
        }
        Node* leftTreeHead = NULL;
        Node* rightTreeHead = NULL;
        Node* leftTreeTail = NULL;
        Node* rightTreeTail = NULL;
        //后根序遍历
        leftTreeHead = TransformTreeToList(root->left);   //找到左子树构建的的循环链表
        rightTreeHead = TransformTreeToList(root->right); //找到右子树构建的循环链表
        if (leftTreeHead == NULL && rightTreeHead == NULL) {
            root->left = root->right = root;//无叶子节点，创建1个单一节点的指向自己的循环链表
            return root;
        }
        //将根节点放到左子树的循环链表最末尾
        if (leftTreeHead != NULL) {
            leftTreeTail = leftTreeHead->left;
            leftTreeTail->right = root;
            root->left = leftTreeTail;
            root->right = leftTreeHead;
            leftTreeHead->left = root;
            leftTreeTail = root;     
        } else {
            leftTreeTail = leftTreeHead = root->left = root->right = root;
        }
        //将已合并根节点的左子树与右子树合并
        if (rightTreeHead != NULL) {        
            rightTreeTail = rightTreeHead->left;
            leftTreeTail->right = rightTreeHead;
            rightTreeHead->left = leftTreeTail;
            leftTreeHead->left = rightTreeTail;
            rightTreeTail->right = leftTreeHead;
        }
        //左子树的头是最后循环链表的头
        return leftTreeHead; 
    }

    Node* treeToDoublyList(Node* root) 
    {
        return TransformTreeToList(root);
    }
};
![无标题.png](https://pic.leetcode-cn.com/d36797010d7a970a7622fbbcda7d96f7462e4154d9db318615744e46c37e62f7-%E6%97%A0%E6%A0%87%E9%A2%98.png)

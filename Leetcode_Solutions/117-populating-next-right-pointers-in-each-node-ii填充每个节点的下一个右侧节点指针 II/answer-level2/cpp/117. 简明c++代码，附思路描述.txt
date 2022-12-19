步骤：
-递归的方法，对于一个节点来说，首先连接他的左子树和右子树（如果有的话）。
-如果该节点存在next且next有左或右子树，那么连接该节点的孩子与next的孩子，如果next没有孩子，则迭代寻找next的next，直到next出现左或右。
     这需要递归先右子树再递归左子树，因为只有一层level中右边先连起来了，左边往右迭代next时才会不断层的找到有孩子的next
然后连接该节点的孩子与next的孩子
-递归右，再递归左孩子

### 代码
```
class Solution {
public:
    Node* connect(Node* root) {

        if(root){
            Node* nextNode = root->next;
            while(nextNode && !(nextNode->left || nextNode->right)){
                nextNode = nextNode -> next;
            }
            if(nextNode){
                if(root->right){
                    if(nextNode->left)
                        root->right->next = nextNode->left;
                    else if(nextNode->right)
                        root->right->next = nextNode->right;
                }
                else if(root->left){
                    if(nextNode->left)
                        root->left->next = nextNode->left;
                    else if(nextNode->right)
                        root->left->next = nextNode->right;

                }
            }
            if(root->left && root->right)
                root->left->next = root->right;
            connect(root->right);
            connect(root->left);
            return root;
        }
        else
            return NULL;
    }
};

```
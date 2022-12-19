### 解题思路
利用“搜索排序树” “中序遍历” 是递增的解决这个问题。
### 方法1

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode *Front,* First, * Second;
    int _min;
    void recoverTree(TreeNode* root) {
        Front = First = Second = NULL;
        if(root == NULL) return;
        inOrder(root);//中序遍历
        if(First == NULL) return;


        int t;
        t = First->val;
        First->val = Second->val;
        Second->val = t;
    }

    // 中序遍历
    void inOrder(TreeNode * root){
        if(root == NULL) return;
        inOrder(root->left);
        if(Front != NULL) {
            if(First == NULL && Front->val > root->val){
                First = Front;
                _min = Front->val; // 初始化最小值
            }
            if(First != NULL){
                // 更新最小值
                if(root->val < _min){
                    _min = root->val;
                    Second = root;
                }
            }
        }
        Front = root; // 更新Front
        inOrder(root->right);
    }
};
```

### 方法2

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
TreeNode* sortList[1000]; // 可以改为动态数组降低空间的使用
int idx = 0;
    TreeNode* recoverTree(TreeNode* root) {
        if(root == NULL) return root;
        // 遍历
        inOrder(root);

        int idxa,idxb;
        idxa = idxb = -1;
        for(int i=0;i<idx;i++){
            cout<<sortList[i]->val<<" ";
            if( idxa == -1 && sortList[i]->val > sortList[i + 1]->val){
                idxa = i;continue;
            }
                
            if( idxa != -1 && sortList[idxa]->val > sortList[i]->val){
                idxb = i; // break; 为了找到全局最小
            }
        }
        cout<<endl;
        cout<<"idxa:"<<idxa<<endl;
        cout<<"idxb:"<<idxb<<endl;
        int t;
        t = sortList[idxa]->val;
        sortList[idxa]->val = sortList[idxb]->val;
        sortList[idxb]->val = t;

        return root;
    }

    // 中序遍历
    void inOrder(TreeNode * root){
        if(root == NULL) return;
        inOrder(root->left);

        sortList[idx++] = root;
        
        inOrder(root->right);
    }
};
```
### 解题思路
此处撰写解题思路

### 代码

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
//countA和countB表示当前层，同层才能A,B同时遍历或者A,B比较值
    void TraversalAB(TreeNode * A,TreeNode * B,bool & flag,int & countA,int & countB)
    {
        if(!A&&!B)
        {
            countA--;
            countB--;
            return;
        }
        if(!A)
        {
            countA--;return;
        }
        if(!B)
        {
            countB--;return;
        }
        if(countA==countB)
        {
            //先比较值
            if(A->val!=B->val)
            {
                cout << "no match!"<<endl;
                flag = false;
                return;
            }
            //再判断遍历方向

            //B有A没有
            if((!A->left&&B->left)||(!A->right&&B->right))
            {
                cout << "B has but A not"<<endl;
                flag = false;
                return;
            }
            //A,B都有
            if(A->left&&B->left)
            {
                TraversalAB(A->left,B->left,flag,++countA,++countB);
            }
            if(A->right&&B->right)
            {
                TraversalAB(A->right,B->right,flag,++countA,++countB);
            }
            //A有B没有
            if(A->left&&!B->left)
            {
                TraversalAB(A->left,B,flag,++countA,countB);
            }
            else if(A->right&&!B->right)
            {
                TraversalAB(A->right,B,flag,++countA,countB);
            }
            //A、B都没有
            if(!A->left&&!B->left&&!A->right&&!B->right)
            {
                countA--;
                countB--;
                return;
            }
            // else 
            // {
            //     flag = false;
            //     return;
            // }
        }
        else
        {
            TraversalAB(A->left,B,flag,++countA,countB);
            TraversalAB(A->right,B,flag,++countA,countB);
        }

    }

    void Traversal(TreeNode * A,TreeNode *B,bool & flag)
    {
        if(!A)
            return;
        if(A->val == B->val)
        {
            cout << "one match! "<<endl;
            int countA = 1;
            int countB = 1;
            flag = true;
            TraversalAB(A,B,flag,countA,countB);
            if(flag)
                return;
        }
        Traversal(A->left,B,flag);
        Traversal(A->right,B,flag);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!B||!A)
            return false;
        bool flag = false;
        Traversal(A,B,flag);
        return flag;
    }
};
```
### 解题思路
执行用时 :
60 ms
, 在所有 C++ 提交中击败了
43.59%
的用户
内存消耗 :
35.7 MB
, 在所有 C++ 提交中击败了
100.00%
的用户
如果两个当中有一个是空指针就是错的
两个两个比较，头节点不相等找a的左子树右子树继续比较
因为b的结构是属于a，所欲b是空指针说明剩下的没有，这里返回正确，如果是b有东西a是空指针就返回错误，接下来继续递归比较

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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==NULL||B==NULL)
        {
            return false;
        }
        else 
        return isright(A, B)||isSubStructure(A->left, B)||isSubStructure( A->right, B);
    }


    bool isright(TreeNode* A, TreeNode* B)
{


    if(B==NULL)
    {
        return true;
    }
    if(A==NULL)
    {
        return false;
    }

     
    return  A->val==B->val&&isright( A->left, B->left)&&isright( A->right, B->right);
        
        
   
   
   

}




};
```
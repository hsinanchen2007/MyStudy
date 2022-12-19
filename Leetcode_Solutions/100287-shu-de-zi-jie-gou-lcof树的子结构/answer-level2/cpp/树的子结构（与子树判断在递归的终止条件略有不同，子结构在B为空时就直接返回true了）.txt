### 解题思路
 这玩意想到就写，在我一开始还不相信自己写得出来，总感觉这里条件可能不能判断好，总之一句话，相信自己，敢写，不仅感想，还要敢写。。

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
    bool flag=false;
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==nullptr||B==nullptr ) return false  //有一个为空就不符合;
        return isSubStructure(A->left,B)||isSubStructure(A->right,B)||isSubStructure1(A,B); //有一个符合就行
    }
    bool isSubStructure1(TreeNode* A, TreeNode* B) {
        if(B==nullptr) return true;  //只要B中能够递归到空节点，说明之前的遍历是符合的
        if(A==nullptr) return false;//此时B肯定不为空节点，如果A此时为空的话，找不到与B的值匹配的
        if(A->val==B->val){         //值相等就进行下一次循环
            return isSubStructure1(A->left,B->left)&&isSubStructure1(A->right,B->right);
        }
        return false;
    }
};
```
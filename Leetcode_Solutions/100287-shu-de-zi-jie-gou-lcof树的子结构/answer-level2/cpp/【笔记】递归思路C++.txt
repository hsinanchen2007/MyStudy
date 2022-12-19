### 解题思路
判断一个B树在不在A树中，简单想法是这样，（1）找到A树中与B树的根节点值相等的节点（2）在检测剩余节点是否相等，我们实现的helper()就是这个作用。。
下面的思路就简单了，使用一种遍历的方法，找到A中与B根节点相等的字节点，然后观察两者的结构是否一致。
遍历的方法有两种一种是递归遍历另一种是非递归遍历，本答案采用了递归的解法。
在和递归结合时，我们并没有简单的遍历查找相等的节点，而是，换了一个角度，如果A中有一节点与B根节点相等，那么这个字节点要么作为根节点，要么作为
左子节点或者是右子节点，让他们分别与B相比较就好了

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
    bool helper(TreeNode* A,TreeNode* B){
        //A为NULL，则一定为false
        if(!B ){
            return true;
        }

        //在B不为NULL的情况下
        if(B&&!A){
            return false;
        }

        if(A->val == B->val && helper(A->left,B->left) && helper(A->right, B->right)){
            return true;
        }else{
            return false;
        }
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B)    return false;

        //A从根结点与B树一致的情况
        if(helper(A,B)) return true;

        return isSubStructure(A->left,B) || isSubStructure(A->right, B);
    }
};
```
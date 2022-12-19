### 解题思路
思路是：构建一个A的递归循环（剑指上是通过定义一个result,当result为true时就不再递归了
if(Equal(pRoot1-> val , pRoot2-> val))
result = DoesHaveTree2(pRoot1, pRoot2);
if(!result)
result = HasSubtree(pRoot1->left,pRoot2) ;
if(!result)
result = HasSubtree(pRoot1-> right , pRoot2);

然后判断每次A递归时是否满足B与A的当前根节点值相同，如果相同则试着进入A\B共同遍历，注意遍历判断，除了判断值是否相同，
还可以通过
if(B == nullptr)
    return true;
if(A == nullptr)
    return false;
来简化判断

下面的代码注意判断里的逻辑，||与&&小心书写，以及&&左右条件应该是些啥，下面B和A的遍历采用的是层次遍历。剑指里用的是普通递归

还有注意int可以直接通过==判断是否相等，剑指里数据类型是double，double必须自己定义一个equal函数来判断，当abs(a-b)<0.00000001可认为相等
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
        TreeNode* pATreeNode = A;
        TreeNode* pBTreeNode = B;
        if(pATreeNode ==nullptr && pBTreeNode == nullptr)
            return true;
        else if(pATreeNode ==nullptr || pBTreeNode == nullptr)
            return false;

        if(pATreeNode->val == pBTreeNode->val){
            queue<TreeNode*> queA;
            queue<TreeNode*> queB;
            queA.push(pATreeNode);
            queB.push(pBTreeNode);
            while(!queA.empty() && !queB.empty()){
                if (queA.front()->val != queB.front()->val)
                    break;
                if(queA.front()->left != nullptr && queB.front()->left != nullptr){
                    queA.push(queA.front()->left);
                    queB.push(queB.front()->left);
                }
                else if(queA.front()->left == nullptr && queB.front()->left == nullptr){
                }
                else if(queA.front()->left == nullptr && queB.front()->left != nullptr){
                    break;
                }
                if(queA.front()->right != nullptr && queB.front()->right != nullptr){
                    queA.push(queA.front()->right);
                    queB.push(queB.front()->right);
                }
                else if(queA.front()->right == nullptr && queB.front()->right == nullptr){
                }
                else if(queA.front()->right == nullptr && queB.front()->right != nullptr){
                    break;
                }
                queA.pop();
                queB.pop();                
            }
            if (queA.empty() && queB.empty())
                return true ;
        }

        return isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }

};
```
### 解题思路
官方方法一：递归
我们可以对这两棵树同时进行前序遍历，并将对应的节点进行合并。
在遍历时，如果两棵树的当前节点均不为空，我们就将它们的值进行相加，并对它们的左孩子和右孩子进行递归合并；如果其中有一棵树为空，那么我们返回另一颗树作为结果；如果两棵树均为空，此时返回任意一棵树均可（因为都是空）。

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        
        if(t1==NULL){
            return t2;
        }
        if(t2==NULL){
            return t1;
        } 
        queue<TreeNode*> q;  //利用一个队列就行了
        q.push(t1);
        q.push(t2);
        while(!q.empty()){
            TreeNode* r1 = q.front();
            q.pop();  //同时front 两次是白扯，得pop之后才能再pop
			TreeNode* r2 = q.front(); //是相邻的两个元素，都是两两同时操作的
            q.pop();
            r1->val = r1->val + r2->val;   //2 合并到1中
            if(r1->left&&r2->left){
                q.push(r1->left);
                q.push(r2->left);
            }else if(r1->left==NULL){
                r1->left = r2->left;
            }
            if(r1->right&&r2->right){
                q.push(r1->right);
                q.push(r2->right);
            }
            else if(r1->right==NULL){
                r1->right = r2->right;
            }            
        }
        return t1;
                //想用前序遍历，没行
                // TreeNode* p1=t1;
                // TreeNode* p2=t2;
                // TreeNode* p = new TreeNode());
                // stack<int> s1;
                // stack<int> s2;
                // while(p1||p2||s1.size()||s2.size()){
                //     while(p1||p2){
                //         if(p1&p2){
                //             p->val = p1->val + p2->val;
                //         }else if(p1){
                //             p->val = p1->val;
                //         }else if(p2){
                //             p->val = p2->val;
                //         }
                //         s1.push(p1);
                //         s2.push(p2);
                //         p=p->left;
                //     }
                //     p1=s1.top();
                //     s1.pop();
                //     p2=s2.top();
                //     s2.pop();
                // }

        // //递归 看到答案才勉强明白了吧，是吧2 加到1上了。
        // if(t1==NULL) return t2;
        // if(t2==NULL) return t1;
        // t1->val += t2->val;   
        // t1->left = mergeTrees(t1->left,t2->left);
        // t1->right = mergeTrees(t1->right,t2->right);
        // return t1;

    }
};
```
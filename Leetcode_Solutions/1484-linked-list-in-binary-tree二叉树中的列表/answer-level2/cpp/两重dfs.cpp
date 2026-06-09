**思路：**
第一个dfs是遍历整棵树找到起始点，即第一个相同的点。
第二个dfs是从起始点开始匹配剩下的点。
**代码：**
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool cmp(ListNode* head,TreeNode* root){
        bool ans=false;
        if(head==NULL){//匹配完成
            ans=true;
        }
        if(head!=NULL&&root!=NULL&&head->val==root->val){//两个都不为空，而且当前点相同，则匹配下一个点
            if(cmp(head->next,root->left)||cmp(head->next,root->right)){//分别匹配左边和右边。
                ans=true;
            }
        }
        return ans;
    }

    bool findstart(ListNode* head,TreeNode* root){
        if(root==NULL)return false;
        bool res=false;
        if(head->val==root->val){//相同，则为起始点，对比剩下的点。
            res =  cmp(head,root);
        }
        if(res)return res;//如果匹配成功，直接返回结果
        res = findstart(head,root->left)||findstart(head,root->right);//匹配不成功，则往左子树和右子树继续查找起始点。
        return res;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        bool res=findstart(head,root);
        return res;
    }
};
```
### 解题思路
有点投机取巧的方法:把链表转换为string,然后前序遍历,也用一个string保存节点上的值，每到一个根节点就可以调用string中的find函数进行判断

### 代码

```cpp
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
    bool ans=false;
    bool isSubPath(ListNode* head, TreeNode* root) {
        string curr="";
        string q="";
        while(head){
            q+=to_string(head->val);
            head=head->next;
        }
        find(root,curr,q);
        return ans;
    }
    void find(TreeNode*root,string q,string t){
        if(ans)
            return;
        if(!root){
            if(q.find(t)!=string::npos)
                ans=true;
            return;
        }
        q+=to_string(root->val);
        find(root->left,q,t);
        find(root->right,q,t);
    }
};
```
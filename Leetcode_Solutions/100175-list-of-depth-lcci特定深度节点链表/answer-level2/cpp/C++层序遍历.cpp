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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        deque<TreeNode*>d1;
        d1.emplace_back(tree);
        vector<ListNode*>vec;
        while(!d1.empty()){
           auto num=d1.size();
           ListNode *first=new ListNode(0);
           ListNode *p=first;
           for(size_t i=0;i<num;++i){
                tree=d1.front();
                d1.pop_front();
                ListNode *s=new ListNode(0);
                s->val=tree->val;
                p->next=s;
                p=s;
                if(tree->left!=NULL)d1.emplace_back(tree->left);
                if(tree->right!=NULL)d1.emplace_back(tree->right);
           }
           p->next=NULL;
           vec.emplace_back(first->next);//这是一个带头结点的链表,和其他链表一样返回头之后的值
        }
        return vec;
    }
};
```
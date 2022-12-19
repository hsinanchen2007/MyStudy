### 解题思路
此处撰写解题思路

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
    TreeNode* CreateBST(vector<ListNode*> v_l){
    	TreeNode* bst = new TreeNode(v_l[v_l.size()/2]->val);

    	vector<ListNode*> v_l_left(v_l.begin(), v_l.begin() + v_l.size()/2);
    	vector<ListNode*> v_l_right(v_l.begin() + v_l.size()/2+1, v_l.end());
    	if(v_l_left.size()){
    		bst->left = CreateBST(v_l_left);
    	}
    	if(v_l_right.size()){
    		bst->right = CreateBST(v_l_right);
    	}

    	return bst;
    }
    TreeNode* sortedListToBST(ListNode* head) {
    	if(!head) return NULL;
    	vector<ListNode*> v_list;
    	while(head){
    		v_list.push_back(head);
    		head = head->next;
    	}
    	TreeNode* bst = CreateBST(v_list);
    	return bst;
    }
};
```
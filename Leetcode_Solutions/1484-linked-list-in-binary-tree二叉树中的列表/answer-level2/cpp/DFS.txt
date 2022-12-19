### 解题思路
对树进行DFS搜索，深入搜索的条件是相等
设置flag，及时终止代码
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
vector<int> to_vector(ListNode *head){
    vector<int> ret;
    for(auto it = head; it; it = it->next)
        ret.push_back(it->val);
    return ret;
}
class Solution {
public:
    vector<int> v;
    bool flag;
    void go(TreeNode *x, int k){
        if(flag) return;
        if(k+1 == v.size()){
            flag = 1;
            return;
        }
        //相等，才向下遍历，不然直接终止
        if(x->left && x->left->val == v[k+1])
            go(x->left, k+1);
        if(x->right && x->right->val == v[k+1])
            go(x->right,k+1);
    }
    
    void dfs(TreeNode *x){
        if(!x) return;
        if(flag) return;
        if(x->val == v[0]){ //首先找起点，找到后启动
            go(x, 0);
        }
        dfs(x->left);
        dfs(x->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head) return 1;
        v = to_vector(head);
        flag = 0;
        dfs(root);
        return flag;
    }
};
```
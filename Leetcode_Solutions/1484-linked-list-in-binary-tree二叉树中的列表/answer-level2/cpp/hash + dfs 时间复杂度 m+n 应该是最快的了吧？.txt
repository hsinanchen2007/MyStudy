```
class Solution {
public:
    const int P = 131;
    unsigned long long pre = 0;
    unsigned long long p = 1;
    int size = 0;
    unordered_map<int, unsigned long long> s;
    bool fun(TreeNode* root, unsigned long long cur, int level) {
        if(root == NULL) return false;
        cur = cur*P + root->val;
        if(level >= size) if(cur - s[level-size]*p == pre) return true;
        s[level] = cur;
        return fun(root->left, cur, level+1) || fun(root->right, cur, level+1);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        while(head != NULL) {
            ++size;
            p = p*P;
            pre = pre*P+head->val;
            head = head->next;
        }
        s[0] = 0;
        return fun(root, 0, 1);
    }
};
```

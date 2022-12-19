递归，利用栈print

```C++
class Solution {
public:
    void print(ListNode* head, vector<int>& reverse) {
        if (head == NULL) return;
        print(head->next, reverse);
        reverse.push_back(head->val);
    }
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        print(head, ans);
        return ans;
    }
};
```

复杂度O(n)
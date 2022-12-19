![image.png](https://pic.leetcode-cn.com/2e318200e0b8996f097a79cb75a8873c947230757e4d458c081af0b603ebcad9-image.png)

顺序：橙色->红色->蓝色->紫色

```

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        auto left = dummy, right = head;
        int cnt = m - 1;
        while(cnt--)
        {
            left = right;
            right = right->next;
        }


        auto savehead = left;
        auto savetail = right;
        left = right;
        right = right->next;
        cnt = n - m;
        while(cnt--) 
        {
            auto nxt = right->next;
            right->next = left;
            left = right;
            right = nxt;
        }
        savehead->next = left;
        savetail->next = right;
        return dummy->next;
    }
};

```


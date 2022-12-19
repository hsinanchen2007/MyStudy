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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || head->next == NULL || m == n)return head;       
        auto newhead = new ListNode(-1);
        newhead->next = head;

        auto prim = newhead;
        for(int i = 0;i < m-1;++i)prim = prim->next;
        auto a = prim->next;
        auto b = a->next;

        int num = n-m;
        ListNode* c;
        //从m到n翻转
        while(num > 0){
            c = b->next;
            b->next = a;
            --num;
            if(num <= 0)break;
            a = b;
            b = c;
        }

        prim->next->next = c;
        prim->next = b;
        return newhead->next;
    }
};
```
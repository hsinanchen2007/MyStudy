### 解题思路
题解Java区大佬的C++ 版本，结果很慢，不如C语言直接两指针暴力搜索

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return head;
        map<int,ListNode*> map;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int sum = 0;
        for(ListNode*p=dummy;p;p=p->next){
            sum+=p->val;
            map[sum] = p;
        }
        sum = 0;
        for(ListNode*p=dummy;p;p=p->next){
            sum+=p->val;
            p->next = map[sum]->next;
        }
        return dummy->next;
    }
};
```
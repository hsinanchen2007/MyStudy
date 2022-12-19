## 思路
1. 先找到m的前一个节点。
2. 由m节点向后遍历，同时反转链表，在反转当前元素的指针前先保存当前元素下一个节点next。
3. 修改反转链表前后指针。
## 代码
```c++
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {             
        if (head == nullptr || head->next == nullptr || m >= n) {
            return head;
        }
        int i = 1;
        ListNode *mPre = nullptr;
        ListNode *cur = head;
        ListNode *pre = nullptr;
        //找m前一个节点mpre
        while (i < m) {
            mPre = cur;
            cur =  cur->next;
            i++;
        }
        ListNode *mNode = cur;
        //反转[m, n]
        ListNode *next = nullptr;
        while (i < n+1) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            i++;
        }
        //修改原m节点前一个节点指针
        if (m == 1) {
            head = pre;
        } else {
            mPre->next = pre;
        }
        //修改反转链表（反转链表最后一个节点为m）的下一个节点指针
        mNode->next = next;
        return head;
    }
};
```

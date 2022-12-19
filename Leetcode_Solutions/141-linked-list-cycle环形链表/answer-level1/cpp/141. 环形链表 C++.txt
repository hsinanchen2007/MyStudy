### 解题思路
1.使用双指针，一个是慢指针，一个快指针，可以把两个指针想想成两个运动员做跑步比赛。
2.若链表不是环形的那么快指针会以较快的速度跑到链表的结尾，因此发现fast指针指向null后就直接返回false。
3.若链表是环形的那么快指针会进入循环，因此会有当快指针和慢指针指向同一个结点的情况，所以最后返回true。

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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow != fast){
            if(fast == NULL || fast->next == NULL){
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
```
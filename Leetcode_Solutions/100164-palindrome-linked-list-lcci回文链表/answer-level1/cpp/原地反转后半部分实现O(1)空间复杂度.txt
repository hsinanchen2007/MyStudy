### 解题思路
要实现O(n)的时间复杂度与O(1)的空间复杂度，关键在于原地反转后半部分链表。

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
    bool isPalindrome(ListNode* head) {
        //利用双指针找到链表的终点位置;
        ListNode* next = head;
        ListNode* mid = head;
        while(next!=NULL && next->next!=NULL){
            next = next->next->next;
            if(next==NULL || next->next==NULL){//将前半部分链表的最后一个元素指向nullptr;
                ListNode* temp = mid->next;
                mid->next = NULL;
                mid = temp;
                break;
            }
            mid = mid->next;
        }
        //原地反转链表
        ListNode *reverse = nullptr;
        while(mid != NULL){
            ListNode *temp = mid->next;
            mid->next = reverse;
            reverse = mid;
            mid = temp;
        }
        //比较两部分
        ListNode* next1 = head;
        ListNode* next2 = reverse;
        while(next1!=NULL && next2!=NULL){
            if(next1->val != next2->val) return false;
            next1 = next1->next;
            next2 = next2->next;
        }
        return true;
    }
};
```
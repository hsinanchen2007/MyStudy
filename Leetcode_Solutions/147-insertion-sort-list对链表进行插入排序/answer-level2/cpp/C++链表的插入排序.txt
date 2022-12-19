### 解题思路
与普通插入排序思路一致
![147链表的插入排序.mp4](5dd98a6f-ae78-45ca-b378-9fee35f4ccdb)
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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode * dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode * begNode = dummyHead;
        ListNode * tailNode = head;
        ListNode * curNode = head->next;
        ListNode * nexNode = NULL;
        while(curNode != NULL){
            nexNode = curNode->next;
            begNode = dummyHead;
            while(curNode->val >= begNode->next->val){
                begNode = begNode->next;
                if(begNode->next == curNode){
                    tailNode = curNode;
                    break;
                }
            }
            if(begNode->next != curNode){
                tailNode->next = nexNode;
                curNode->next = begNode->next;
                begNode->next = curNode;
            }
            curNode = nexNode;
        }
        ListNode * res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};
```
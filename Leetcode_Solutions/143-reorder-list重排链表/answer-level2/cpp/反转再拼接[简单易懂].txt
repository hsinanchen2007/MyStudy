### 解题思路
1、快慢指针，算出队列中间节点；
2、将慢指针指向的后半队列进行链表反转；
3、合并左半链表和右半链表(已反转);
4、输出新链表Header;

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
    void reorderList(ListNode* head) {
        ListNode* slowList = head;
        ListNode* fastList = head;
        while (fastList != nullptr && fastList->next != nullptr) {
            slowList = slowList->next;
            fastList = fastList->next->next;
        }
        //反转链表
        ListNode* prev = nullptr;
        ListNode* cur = slowList;
        ListNode* next = nullptr;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        //两个链表 一个是heade，一个是prev，当前prev指向最后端,开始合并
        ListNode* newNode = new ListNode(0);
        ListNode* tmpNode = newNode;
        while(head != slowList || prev != nullptr) {
            if (head != slowList) {
                tmpNode->next = head;
                tmpNode = tmpNode->next;
                head = head->next;
            }
            if (prev != nullptr) {
                tmpNode->next = prev;
                tmpNode = tmpNode->next;
                prev = prev->next;
            }
        }
        head = newNode->next;
    }
};
```
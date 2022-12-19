### 解题思路（一）先确定新链表的头节点
建立一个新链表，因为两个链表都是升序，那么每次只需要比较两个链表的头节点，然后将值较小的节点通过尾插法插入到新链表的尾部，当其中一个链表遍历完之后，将另一个链表剩下的部分直接链接到新链表的尾部。

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)  return nullptr;     // 当l1和l2都为空时返回空
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        // 当l1和l2都不为空时
        ListNode* newList;
        ListNode* newListTail;
        if(l1->val < l2->val){
            newList = l1;
            l1 = l1->next;
            newListTail = newList;
            newList->next = nullptr;
        }
        else{
            newList = l2;
            l2 = l2->next;
            newListTail = newList;
            newList->next = nullptr;
        }

        while(l1 && l2){
            // 当l1和l2都不为空时，选择一个比较小的节点，采用尾插法插入到新链表中
            if(l1->val < l2->val){
                newListTail->next = l1;  // 将p插到新链表的尾部
                l1 = l1->next;            // p指向原链表的下一个节点      
                newListTail = newListTail->next;    // 新链表的尾指针向后移动
                newListTail->next = nullptr;        // 新链表末尾next指向空
            }
            else{
                newListTail->next = l2;      // 将q插入到新链表尾部
                l2 = l2->next;            // q指向原链表的下一个节点
                newListTail = newListTail->next;    // 新链表的尾指针向后移动 
                newListTail->next = nullptr;        // 新链表末尾next指向空
            }
        }
        if(l1){
            // 如果最后剩下p，那么将p剩下的元素全部放到新链表的末尾
            newListTail->next = l1;
        }
        if(l2){
            // 如果最后剩下q,那么将q剩下的元素全部放到新链表的末尾
            newListTail->next = l2;
        }
        return newList;
    }
};
```

## 解题思路（二） 采用伪头节点

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)  return nullptr;     // 当l1和l2都为空时返回空
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        // 当l1和l2都不为空时
        ListNode* newList;
        ListNode* newListTail = new ListNode(0);
        newList = newListTail;

        while(l1 && l2){
            // 当l1和l2都不为空时，选择一个比较小的节点，采用尾插法插入到新链表中
            if(l1->val < l2->val){
                newListTail->next = l1;  // 将p插到新链表的尾部
                l1 = l1->next;            // p指向原链表的下一个节点      
                newListTail = newListTail->next;    // 新链表的尾指针向后移动
            }
            else{
                newListTail->next = l2;      // 将q插入到新链表尾部
                l2 = l2->next;            // q指向原链表的下一个节点
                newListTail = newListTail->next;    // 新链表的尾指针向后移动 
            }
        }
        if(l1){
            // 如果最后剩下p，那么将p剩下的元素全部放到新链表的末尾
            newListTail->next = l1;
        }
        if(l2){
            // 如果最后剩下q,那么将q剩下的元素全部放到新链表的末尾
            newListTail->next = l2;
        }
        return newList->next;
    }
};
```
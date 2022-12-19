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
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL || head->next == NULL) return head;

    ListNode* l1 = head;

    ListNode* l2 = head->next,*even = head->next;　

    //head做奇数表头，even做偶数表头。l1,l2两个遍历指针


    while(l2!= NULL && l2->next != NULL){

         l1->next = l2->next;
        l1 = l2->next;
        l2->next = l1->next;
        l2 = l1->next;
    }


    l1->next = even;
    
    
    return head;
    

    }
};
```
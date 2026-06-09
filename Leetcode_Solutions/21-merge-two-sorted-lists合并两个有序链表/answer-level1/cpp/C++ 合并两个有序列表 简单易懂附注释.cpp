### 解题思路
题解分为三个板块：
1.对输入其一或全部为nullptr的判断,并对l1、l2第一个元素的比较后，始终使l1为较小首元素的链表，以便后面模版化处理 
2.维护l1->next与l2并不断迭代:其中分为：在首、尾分别l1->next连续比l2小的部分；l1->next比l2大的部分（注意l2插入后仍要把原来的l1->next接上） 
3.第二部分处理完后，对l2还有剩余部分没接上的处理

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
        if(l1 == nullptr)return l2;//always remember empty case
        if(l2 == nullptr)return l1;
        if(l1->val > l2->val){//swap for excuting uniform next-step operation
            swap(l1,l2);
        }
        ListNode* head = l1;
        ListNode* temp1;
        while (l1->next != nullptr && l2 != nullptr){
            if(l2 == nullptr || l1->next->val <= l2->val){
                l1 = l1->next;
                continue;
            }
            if(l1->next->val > l2->val){
                temp1 = l1->next;
                l1->next = l2;
                l2 = l2->next;
                l1->next->next = temp1;
                
            }
        }
        //if l1 != nullptr after iteration, 
        //l1 has rest part that larger than last element of l1,
        //it is ok because l1 is connected linked list
        //if l2 != nullptr after iteration,
        //l2 has rest part not connected to l1
        if(l2 != nullptr)l1->next = l2;
        return head;
        
    }
};
```
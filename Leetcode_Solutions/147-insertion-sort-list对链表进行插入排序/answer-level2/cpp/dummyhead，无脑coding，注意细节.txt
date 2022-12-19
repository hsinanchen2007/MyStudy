
用链表模拟插入排序，因为要修改链表的位置，所以用pre来记录前一个节点，方便操作。 
因为需要pre，所以设置dummyhead作为head的pre。

```
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
        ListNode * dummyHead = new ListNode(0);
        ListNode * cur = head;
        dummyHead->next = head;
        ListNode * pre = dummyHead;
        while(cur != NULL){
            bool find = false;
            ListNode* cur1 = dummyHead->next;
            ListNode * pre1 = dummyHead;
            while(cur1 != NULL && cur1 !=cur){ // 当前元素之前的
                if(cur1->val > cur->val){ // 发现逆序。 交换
                    find = 1;
                    pre->next = cur->next;
                    pre1->next = cur;
                    cur->next = cur1;
                    cur = pre->next;
                    break;
                }
                pre1 = cur1;
                cur1 = cur1->next;
            }
            if(!find){
                pre = cur;
                cur = cur->next;
            }
        }
        return  dummyHead->next;
    }
};
```

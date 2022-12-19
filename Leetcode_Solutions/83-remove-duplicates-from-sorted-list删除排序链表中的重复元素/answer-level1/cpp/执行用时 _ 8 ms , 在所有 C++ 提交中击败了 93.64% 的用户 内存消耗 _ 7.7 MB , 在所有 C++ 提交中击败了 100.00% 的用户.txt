### 解题思路
声明两个指针，用来移动，边移动边比较，边删除

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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head==NULL){
          return head;
        }
        ListNode *L = head;
        ListNode *p = head;
        ListNode *q = head->next;
        while(q!=NULL){
            int nowData = p->val;
            int data = q->val;
            if(data==nowData){ // 把                        
                 p->next = q->next;
                 q= p->next;
            }else{
                p = q;
                q = q->next;
            }
        }
        return L;
    }
};
```
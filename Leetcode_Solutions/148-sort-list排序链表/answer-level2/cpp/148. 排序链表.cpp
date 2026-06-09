### 归并排序
采用归并排序的思路，同时采用快慢指针把一个完整的链表从中间断开，在分别合并两个部分
### 时间/空间复杂度
时间：O（nlogn）
空间：O（1）
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
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* head=new ListNode(0);
        ListNode* cur=head;
        while(l1 && l2){
            if(l1->val<l2->val){
                cur->next=l1;
                cur=cur->next;
                l1=l1->next;
            }else{
                cur->next=l2;
                cur=cur->next;
                l2=l2->next;
            }
        }
        if(l1) cur->next=l1;
        if(l2) cur->next=l2;
        cur=head->next;
        delete head;
        return cur;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *pslow=head,*pfast=head,*pmid=head;
        while(pfast && pfast->next){
            pfast=pfast->next->next;
            pmid=pslow;             
            pslow=pslow->next;      //这样写是为了防止pslow为空时，我们去访问pslow的next
        }
        pmid->next=nullptr;
        return merge(sortList(head),sortList(pslow));
    }
};
```
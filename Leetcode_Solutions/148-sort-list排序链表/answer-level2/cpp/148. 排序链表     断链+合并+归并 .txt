### 解题思路
ListNode* p=head;
        ListNode dummy(0);
        dummy.next=head;


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
    //断链：1.断开部分-》null 2.返回后半部分的头部
    ListNode* cut(ListNode* head, int n){
        ListNode* p=head;//为了防止链表被修改，所以不直接用head
        while(--n&&p){
            p=p->next;
        }
        if(!p) return NULL;
        auto t=p->next;
        p->next=NULL;
        return t;
    }

    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode* p=&dummy;
        while(l1&&l2){
            if(l1->val<l2->val){
            p->next=l1;
             p=l1;
            l1=l1->next;
           
        }
        else{
             p->next=l2;
             p=l2;
            l2=l2->next;
        }
      }
      p->next=l1?l1:l2;
      return dummy.next;  
    }

public:
    ListNode* sortList(ListNode* head) {
        ListNode* p=head;
        ListNode dummy(0);
        dummy.next=head;
        int len=0;
        while(p){
            len++;
            p=p->next;
        }
        for(int size=1;size<=len;size=size*2){
            auto cur=dummy.next;//用于一次循环遍历
            auto tail=&dummy;//因为链会前后断开，所以要保存前一个节点，用于链接合并的链
            while(cur){
                auto left=cur;
                auto right=cut(cur,size);
                cur=cut(right,size);
                tail->next=merge(left,right);//此时这条合并的链条前后都是断开的，所以tail链接前段
                while(tail->next){
                    tail=tail->next;//tail跑到已排好序的尾部，进入下次循环，链接下一段合并链
                }
            }
        }
        return dummy.next;
    }
};
```
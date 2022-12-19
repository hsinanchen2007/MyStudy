### 解题思路
第一次这么干净利落，草稿本上画出来，写出来就完全OK了，发个题解纪念一下。（应该没有副作用的吧，不会被打吧）

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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* res=head->next;

        ListNode* pre=new ListNode(-1);//记录上一组被交换元素的最后一位
        ListNode* p=new ListNode(-1);
        ListNode* q=new ListNode(-1);
        while(head){
            p=head;
            if(p->next) {
                p=p->next;
                pre->next=p;
                q=p->next;
                p->next=head;
                head->next=q;
                pre=head;//保存上次交换的最后一个节点
                head=head->next;
            }
            else return res;  
        }
    return res;
    }
};
```
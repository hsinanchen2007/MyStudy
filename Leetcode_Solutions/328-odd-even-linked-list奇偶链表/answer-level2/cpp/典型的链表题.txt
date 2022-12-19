### 解题思路


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
        if(!head)return head;
        auto p=head;//指向奇数node
        auto q=head->next;//指向偶数node
        auto r=q;//偶数node的开始节点
        auto t=head;//辅助节点 保存偶数节点后的节点
        while(q){
            t = q->next;
            p->next = q->next;
            if(t)
                q->next = t->next;
            p=p->next;
            q=q->next;
        }
        p=head;
        while(p->next){
            p=p->next;
        }
        p->next=r;//把偶数链到奇数节点后面
        return head;
    }
};
```
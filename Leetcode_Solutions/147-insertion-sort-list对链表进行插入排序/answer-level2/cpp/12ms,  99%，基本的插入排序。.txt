
![image.png](https://pic.leetcode-cn.com/84d2afd1c3da161b93a64c148e8d8cddaf2c07e7a2fe6c1b35dd091bb0185d11-image.png)

```
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode * pre = new ListNode(-1);
        pre -> next = head;

        ListNode * tail = head;
        ListNode * node = head->next; 

        while(node){
            if(node->val < tail->val){
                ListNode * cur = pre;
                while(cur->next && node->val >  cur->next->val){
                    cur = cur->next;
                }
                tail->next = node->next;
                node->next = cur->next;
                cur->next =  node;
                node=tail->next;

            }else{
                tail = tail->next;
                node = tail->next;
            }
        }
        return pre->next;
    }
};
```

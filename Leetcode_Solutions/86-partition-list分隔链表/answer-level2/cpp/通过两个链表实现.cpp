通过两个链表实现
![呜呜.jpg](https://pic.leetcode-cn.com/3bdfb7b4edb695028f91af5f15fb38a286189a3fe6c1fc78175991b9ed9c282d-%E5%91%9C%E5%91%9C.jpg)
```
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL){
            return head;
        }
        ListNode *before = new ListNode(-1);//大于3的链表
        ListNode *bef = before;
        ListNode *after = new ListNode(-1);//小于3的链表
        ListNode *aft = after; 
        while(head->next != NULL){
            if(head->val < x){
                bef->next = head;
                bef = bef->next;
                head = head->next;
            }else{
                aft->next = head;
                aft = aft->next;
                head = head->next;
            }
        }
        if(head->val < x){//处理head最后一个节点的值
            bef->next = head;
            bef = bef->next;
        }else{
            aft->next = head;
            aft = aft->next;
        }
        bef->next = after->next;//连接两个链表
        aft->next = NULL;
        return before->next;
    }
};
```



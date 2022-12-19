1. 递归的最后一层返回1，没退回一层返回值自增1，退到返回值==n时，直接删除节点。
2. 最后的返回值<=n时，删除头结点。
```
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int x=removeFun(head, n);
        if(x<=n) return head->next;
        return head;
    }

    int removeFun(ListNode* cur, int n){
        if(cur->next==NULL) return 1;
        int x=removeFun(cur->next, n);
        if(x==n){
            cur->next=cur->next->next;
        }
        return 1+x;
    }
};
```

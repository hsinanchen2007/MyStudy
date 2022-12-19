### 解题思路
首选正向考虑问题，完全模拟即可

### 代码

```cpp
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return 0;
        int n=0;
        for(auto p=head;p;p=p->next) n++;
        k%=n;
        auto first=head,second=head;
        while(k--) first=first->next;
        while(first->next){  //first会停在最后一个结点
            first=first->next;
            second=second->next;
        }
        first->next=head;
        head=second->next;
        second->next=NULL;
        return head;
    }
};
```
### 解题思路
两个指针，快指针先走n步，然后慢指针再走，快指针走到尾，慢指针下一个就是要删除的结点

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(NULL);
        dummy->next = head;  //添加头节点，便于操作
        ListNode *p=dummy;
        ListNode *q=dummy;
        int k=0;
        for(;p!=NULL&&p->next!=NULL;p=p->next){      //一定要注意，判断顺序不能变，因为有可能fast是nullptr，先判断fast->null的话，可能就会出错        
            if(k>=n){
                q=q->next;
            }
            k++;
        }
        q->next=q->next->next;
        return dummy->next;
    }
};
```

```c++
class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        // 思路 ：双指针 quick slow 当快指针指向最后一个时，慢指针指向删除节点的上一个。
        // 逻辑
        // quick先向下走N步 
            // n步不到 长度不到n 无法删除倒数第n个
            // n 步走完 继续向下走 当 quick->next==null slow指向要删除的上一个节点
        ListNode *quick = head,*slow = head,*pdelete;
        for(int i=0;i<n;i++){
            quick = quick->next;
            if(quick == nullptr ){
                if(i==n-1)
                    return head->next;
                else
                    return nullptr;
            }
        }

        while(quick->next !=nullptr){
            quick = quick->next;
            slow = slow->next;
        }
        pdelete = slow->next;
        slow->next = slow->next->next;
        pdelete = nullptr;
        return head;
    }
};
```

```
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dumm = new ListNode(0);
        dumm->next = head;
        ListNode* subhead = dumm;
        ListNode* curr = head;
        while(curr && curr->next)
        {
            int i = k;
            # 头插法对长度为k的部分链表进行翻转
            while(i > 1 && curr->next )
            {
                ListNode* tmp = curr->next;
                curr->next = tmp->next;
                tmp->next = subhead->next;
                subhead->next = tmp;
                i--;
            }
            # 如果还没有完成k次翻转就到达链表尾部，则折回此部分链表的开头，继续头插以恢复顺序
            if(i >= 2)
            {
                int j = k - i;
                curr = subhead->next;
                while(j > 0)
                {
                    ListNode* tmp = curr->next;
                    curr->next = tmp->next;
                    tmp->next = subhead->next;
                    subhead->next = tmp;
                    j--;
                }    
                # 未完成k次翻转说明已到达链表最后一段，恢复最后一段的顺序后直接返回 
                return dumm->next;
            }
            # 操作下一段长度为k的部分链表
            subhead = curr;
            curr = curr->next;
        }
        return dumm->next;
    }
};
```

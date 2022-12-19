每k个翻转一组，使用一个结点指针数组保存翻转过后的头节点，再遍历指针数组将指针数组里的头节点串联起来。
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *p = head;
        int count = 0;
        // 记录链表长度
        while(p!=NULL)
        {
            count++;
            p = p->next;
        }
        // 若k比数组长度大直接返回
        if(k>count) return head;
        int num = count / k;
        ListNode* heads[num + 1];
        ListNode *pre =NULL, *cur = head, *fol = cur->next;
        // 第一层循环代表需要断几次，第二层循环revese这k个结点
        for(int i=0;i<num;i++)
        {
            for(int j=0; j<k; j++)
            {
                cur->next = pre;
                pre = cur;
                cur = fol;
                if(fol!=NULL)
                {
                    fol = fol->next;
                } 
            }
            // 保存翻转过后的头节点并重置pre指针
            heads[i] = pre;
            pre = NULL;
        }
        heads[num] = cur;
        ListNode *q = heads[0];
        for(int i=0;i<num;i++)
        {
            while(q->next!=NULL)
            {
                q = q->next;
            }
            q->next = heads[i+1];
            q = q->next;
        }
        return heads[0];  
    }
};
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeDuplicateNodes(struct ListNode* head){

    struct ListNode* q = NULL;
    struct ListNode* p = NULL;
    struct ListNode* t = NULL;

    if(NULL == head)
    {
        return head;
    }

	// q为要判断的节点，t为q的前一个节点，方便删掉q节点
    t = head;
    q = t->next;
    
    while(NULL != q)
    {
    	// p用来从链表头开始偏移
        p = head;
        while(1)
        {
        	// 若此节点与前面节点的值相同，删除q节点
            if(p->val == q->val)
            {
                t->next = q->next;
                free(q);
                q = t->next;
                break;
            }
			
			// 若此节点与前面节点的值都不同，q往后移
            if(p->next == q)
            {
                q = q->next;
                t = t->next;
                break;
            }
            p = p->next;
        }
    }

    return head;
}
```

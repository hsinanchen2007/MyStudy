[https://michael.blog.csdn.net/](https://michael.blog.csdn.net/)
```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
        	return head;//没有头结点或者一个节点，直接返回
        ListNode *emptyHead = new ListNode(0);//空头结点，编码简化些
        emptyHead->next = head;
        int count = 1;
        ListNode *end = emptyHead, *prev = head, *cur = head->next;
        //end为新链表的结尾
        while(cur != NULL)
        {
        	if(prev->val != cur->val)	//前后不相等了，需要决定是否保留
        	{
                    if(count == 1)	//只出现1次，保留
                    {
                        end->next = prev;	//保留，接上
                        end = prev;		//更新结尾
                    }
                    count = 1;		//count重置为1
        	}
        	else
                    count++;	//前后相等计数+1

            prev = cur;		//更新prev，cur
            cur = cur->next;
        }
        if(count == 1)	//循环结束时cur为空，prev要不要接上？count来判断
            end->next = prev;
        else
            end->next = NULL;
        return emptyHead->next;
    }
};

```

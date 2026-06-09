```
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *nx=head;
        if(head==NULL)
        {
            return head;
        }
        while(nx->next!=NULL)
        {
            int current=nx->val;
            int next_value=nx->next->val;
            if(current==next_value)
            {
                nx->next=nx->next->next;
            }
            else
            {
                nx=nx->next;
            }
        }
        return head;
    }
};
```

2020.1.9 饱读诗书小码农
这是今天的第三道题~
自己在学习C++的时候，因为偷懒所以略过了 链表的知识，现在感觉后悔，但是还是做出来啦~
链表就是要多画图就行~
知识点：
1. 指针的索引改变就相当于删除了元素了这个和数组还是有很大的差别的~
2. 返回的是head 的指针，不要返回nx 哦。 所以要在最开始变化指针的时候，就先要把head 存储起来~
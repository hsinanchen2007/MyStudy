对于链表，每一个新的数字产生包括加数l1->val,加数l2->val,进位tem_r, 只要这三个数全部为零的时候结束，这就是终止条件；
接下来我们需要一个res的链表头作为固定的返回值，一个代理节点cur作为每次新建节点的指针；
在每一次计算的时候，算一个进位，一个取模值，生成一个节点，更新l1,l2,cur;
注：对于l1和l2长度不相同的情况，我这里是将短的置为0的新节点
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* res = new ListNode(0);
        ListNode* cur = new ListNode(0);
        ListNode* temp_node = new ListNode(0);
        res->next = cur;
        char tem_r = 0;
        while(1)
        {
            
            char temp = (l1->val + l2->val + tem_r);
            cur->next =  new ListNode(temp%10);
            cur = cur->next;
            tem_r = temp/10;
            l1 = l1->next;
            l2 = l2->next;
            if(l1==NULL && l2==NULL && tem_r==0 ) break;
            if(l1 == NULL) l1= temp_node;
            if(l2 == NULL) l2= temp_node;
        }
        return res->next->next;
    }
};
```


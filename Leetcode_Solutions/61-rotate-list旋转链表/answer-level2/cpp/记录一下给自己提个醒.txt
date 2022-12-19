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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!(head))   return 0;
        if(!(head->next))   return head;
        ListNode* h=(ListNode*)malloc(sizeof(ListNode));
        h->val=0;
        h->next=head;
        ListNode* t=head;
        int count=0;
        while(true)
        {
            if(t->next!= NULL)
            {
                t=t->next;
                count++;
            }
            else
            {
                t->next=head;
                count++;
                break;
            }
        }
        k%=count;
        int num=count-k;
        while(num>0)
        {
            if(num==1)
            {
                ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
                temp->val = h->val;
                temp->next = h->next;
                head = head->next;
                 h->next = head;
                 temp->next->next = nullptr;
                free(temp);
            }
            else
            {
                head= head->next;
                h->next=head;
            }

            num--;
        }
        return h->next;
        
        
    }
};
```
![微信图片_20190820193713.png](https://pic.leetcode-cn.com/7d9a7c07146fbf3a2f2590f34781947a5e840bbe0f8b56bfb658ef70781114af-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20190820193713.png)

红框中之所以有问题是因为temp本身只是h的指针赋值，不像ListNode* t=head;t是原本就有的空间内存。


方法一：迭代

1.1实现
```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* cur=dummy;

        while(l1&&l2)
        {
            if(l1->val>l2->val)
            {
                swap(l1,l2);//这里只是交换了指针变量中的值，也就是说改变了指针的指向

            }
            cur->next=l1;
            l1=l1->next;
            cur=cur->next;
        }
        if(l1!=NULL) cur->next=l1;
        else
        {
            cur->next=l2;
        }
        return dummy->next;
    }
};
```
1.2实现
```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* cur=dummy;//游标

        while(l1!=NULL&& l2!=NULL)
        {
            if(l1->val<l2->val)
            {
                cur->next=l1;
                l1=l1->next;
            }
            else
            {
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        cur->next=(l1!=NULL)?l1:l2;
        return dummy->next;

    }
};
```
方法二：递归（切忌一点：用递归一定要先想好中止条件）。




```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
        {
            return l2;
        }
        else if(l2==NULL)
        {
            return l1;
        }
        else if(l1->val<l2->val)
        {
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
        
    }
};
```

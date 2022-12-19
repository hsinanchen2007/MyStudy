### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/7d9776d8d381e8f76444211ecad2fa421976692b828f7b04b91caf80f1114086-%E6%8D%95%E8%8E%B7.PNG)

1.首先新建一个头节点，用来保存返回的链表。
2.循环读取两个链表的数值，并将相加的和再加上进位值存入返回链表节点val中，当val>=10时,取个位数，并将进位标志置1.（最大进位就是1）
3.循环结束，如果进位值为1，说明还有进位，需要新建一个节点。将其值存为1，并附在链表的末尾。
over


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode* retl1 = NULL;
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 0;
    head->next = NULL;
    struct ListNode *temp1 = l1;
    struct ListNode *temp2 = l2;
    struct ListNode *temp3 = head;

    int add =0;
    while(temp1 !=  NULL || temp2 != NULL)//开始遍历，直到都是空为止
    {
        struct ListNode *newnode= (struct ListNode*)malloc(sizeof(struct ListNode));
        if(temp1 == NULL)
        {
            newnode->val = add + temp2->val;
            temp2=temp2->next;
        }
        else if(temp2 == NULL)
        {
            newnode->val = add +temp1->val;
            temp1=temp1->next;
        }else
        {
            newnode->val = add + temp1->val + temp2->val;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(newnode->val>=10)
        {
            add = 1; 
            newnode->val %= 10;
            newnode->next = NULL;
        }
        else
        {
            add =0;
            newnode->next = NULL;
        }
        head->next = newnode;
        head=head->next;
    }
    printf("add = %d\n",add);
    if(add ==1)
    {
        struct ListNode *newnode= (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val=1;
        newnode->next=NULL;
        head->next=newnode;
    }
    return temp3->next;
}
```
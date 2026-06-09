### 解题思路
此处撰写解题思路
使用了三个结构体指针（p/q/r），
p用于表示新链表的头指针（我这里创建的是带头结点的链表，为的是后面的循环可以统一操作，不用另外分在头部的情况，也不用担心头指针的丢失）；
q表示新链表的尾部，便于插入新的节点；
r用于创建新的节点，进行放入数据等操作。

我还设立了一个标记量flag，用于表示是否需要进位。
pr1 和 pr2 便于在l1和l2链表上进行遍历。

循环部分就像走路一样:
先双脚并用的跳着走，pr1指向的节点所保留的整数和pr2指向的节点所保留的整数进行相加，再进行相应的操作（是否进位判断，更新flag，创建新节点，存入数据，更新指针...）
当一条链表遍历完时，就像单脚跳着走，只遍历一个链表，再进行相应的操作（是否进位判断，更新flag，创建新节点，存入数据，更新指针...）

flag有几个细节需要注意：
在双脚跳变为单脚跳的时候，可能进了一位，这不要疏忽；
在循环结束的时候，有可能l1和l2的长度一样，最后有可能进了一位，所以要判断flag是否为1，再进行相应的操作。

最后运行的时候，系统要的是不带头节点的新链表，所以最后再加工一下就可以啦！

（个人吐槽：我个人觉得用走路比喻挺形象的，大家看了要是不懂的话，可以留言进行探讨一下！）

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
struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
p->val = -1;
p->next = NULL;
struct ListNode* q = p;
struct ListNode* r = NULL;
int flag,count;
struct ListNode* pr1 = NULL;
struct ListNode* pr2 = NULL;
for (pr1 = l1,pr2 = l2,flag = 0;(pr1||pr2)!=NULL;){
    if (pr1!=NULL&&pr2!=NULL){
        count = pr1->val + pr2->val + flag;
        flag = 0;
        if (count>=10){
            flag = 1;
            count = count%10;
        }

        pr1 = pr1->next;
        pr2 = pr2->next;

        r = (struct ListNode*)malloc(sizeof(struct ListNode));
        r->next = NULL;
        r->val = count;
        q->next = r;
        q = r;
    }
    if (pr1!=NULL&&pr2==NULL){
        count = pr1->val +flag;
        flag = 0;
        if (count>=10){
            flag = 1;
            count = count%10;
        }

        pr1 = pr1->next;

        r = (struct ListNode*)malloc(sizeof(struct ListNode));
        r->next = NULL;
        r->val = count;
        q->next = r;
        q = r;
    }
    if (pr1==NULL&&pr2!=NULL){
        count = pr2->val +flag;
        flag = 0;
        if (count>=10){
            flag = 1;
            count = count%10;
        }

        pr2 = pr2->next;

        r = (struct ListNode*)malloc(sizeof(struct ListNode));
        r->next = NULL;
        r->val = count;
        q->next = r;
        q = r;
    }
}
if (flag == 1){
    r = (struct ListNode*)malloc(sizeof(struct ListNode));
        r->next = NULL;
        r->val = 1;
        q->next = r;
        q = r;
}
r = p;
p = p->next;
free(r);
return p;
}
```
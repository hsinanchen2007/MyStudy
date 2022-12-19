### 解题思路
此处撰写解题思路
本题思路其实和小学的竖式运算思路相同，两个链表的数字相加小于10直接存入新的链表中，大于10就减去10再存入；
### 代码

```c
/**
 * Definition for singly-linked list->
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int i=0; //i为是否进位的标志。
    struct ListNode *add=malloc(sizeof(struct ListNode));
    add->next=malloc(sizeof(struct ListNode));
    struct ListNode *p;
    p=add->next;
    p->val=0;
    p->next=NULL;
    while(l1!=NULL||l2!=NULL||i){ /*当当前的两个链表任意一个不为空且上一位加法发生了进位时进行加法计算。*/
        if(l1!=NULL){
            p->val+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            p->val+=l2->val;
            l2=l2->next;
        }
        if(i==1){   /*需要进位时当前这位的数字+1*/
            p->val++;
            i=0;
        }
        if(p->val>=10){ /*两链表之中的数字相加大于10时发生进位，记录并将这位数字-10*/
            p->val=p->val-10;
            i=1;
        }
        if(l1!=NULL||l2!=NULL||i){ /*当下一步还会发生加法运算时，为新链表创建下一位的空间*/
        p->next=malloc(sizeof(struct ListNode));
        p=p->next;
        p->val=0;
        p->next=NULL;
        }
    }
    add=add->next;
    return add;
}

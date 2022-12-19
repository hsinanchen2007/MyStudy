### 解题思路
从低位开始，当前位加进位，尾插法生成链表
注意最高位向上进位的情况，如[5,5]会产生额外的进位
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
    struct ListNode *L,*s;
    L = (struct ListNode*)malloc(sizeof(struct ListNode)); // 创建头结点，最终需要输出
    struct ListNode *r = L; //r为表尾指针
    int b = 0; //中间变量
    int cb = 0; //进位
    int b1 = 0, b2 = 0;
    while(l1 || l2){ //当l1且l2不为空时
        b1 = l1 ? l1->val : 0;
        b2 = l2 ? l2->val : 0;
        b = b1 + b2 + cb; // 两位的值与进位
        if(b>9){
            cb = 1;b-=10 ;
        }
        else
            cb = 0;
        s = (struct ListNode*)malloc(sizeof(struct ListNode)); // 新节点
        s->val = b; //尾插法
        r->next = s;
        r = s;
        r->next = NULL; //需将末尾置零，否则会调用空指针导致执行产生错误
        b = 0;
        if(l1!=NULL)
            l1=l1->next;
        if(l2!=NULL)
            l2=l2->next;
    }
    if(cb>0){ //尾部补上最高位的进位
        s = (struct ListNode*)malloc(sizeof(struct ListNode)); 
        s->val = cb;
        r->next= s ;
        r = s ;
        r->next = NULL;
    }
    return L->next;
}
```
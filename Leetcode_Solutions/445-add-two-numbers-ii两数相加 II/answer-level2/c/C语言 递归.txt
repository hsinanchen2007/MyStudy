1.找到两个队列中比较长的队列
2.把另外一个队列的值都按位加到这个队列中
2.递归处理进位操作（如果下一个结点为空，则直接用本结点的val计算进位值，否则，本结点的进位值要根据本结点的val和下一个结点的进位值x求和得到）

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int pulsone(struct ListNode* p)
{
    if (p->next != NULL){
        p->val += pulsone(p->next);
        if(p->val >= 10){
            p->val = p->val%10;;
            return 1;
        }
    } else {
         if(p->val >= 10){
            p->val = p->val%10;;
            return 1;
        }
    }

    return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int n, n1, n2, top;
    struct ListNode* head, *p, *p1, *p2, *head1;

    n1 = 0;
    n2 = 0;

    p1 = l1;
    p2 = l2;
    //找长队列
    while ((p1!=NULL)||(p2 != NULL)){
        if (p1 != NULL){
            n1++;
            p1 = p1->next;
        }
        if(p2 != NULL){
            n2++;
            p2 = p2->next;
        }
    }

    n = (n1>n2)?n1:n2;
    head = (n1>=n2)?l1:l2;

    p = head;
    p1 = l1;
    p2 = l2;

    //值都加到长队列中
    while (n>0){
        if ((n1>=n)&&(n2>=n)){
            p->val = p1->val + p2->val;
            p1 = p1->next;
            p2= p2->next;
        } else {
            if (n1>=n){
                p->val = p1->val;
                p1 = p1->next;
            } else {
                p->val = p2->val;
                p2= p2->next;
            }
        }
        n--;
        p = p->next;
    }

    //进位操作
	p = head;
    top = pulsone(p);

    if(top > 0){
        head1 = (struct ListNode*)malloc(sizeof(struct ListNode));
        head1->val = 1;
        head1->next = head;
        return head1;
    } else {
        return head;
    }
}

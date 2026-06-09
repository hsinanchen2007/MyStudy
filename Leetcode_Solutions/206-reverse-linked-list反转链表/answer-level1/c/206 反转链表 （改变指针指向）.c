### 解题思路
1.n获取链表长度
2.遍历n次，每次p结点定位到倒数第二个结点，q = p->next，q则定位到倒数第一个结点
3.创建一个new结点，让new指向q，作为新链表的头结点
4.new结点和head结点一样，都不能随意更改它，否则会丢失新链表。因此创建一个new_p结点，作为游标
5.循环n-2次，其中第一次和最后一次需要特殊处理
6.head = new 
7.return head

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    
    struct ListNode* p = head;// p指向头结点，head结点最好不要动，防止原链表丢失
    struct ListNode* q; // 相当于平常使用的temp，存储临时结点
    struct ListNode* new;
    struct ListNode* new_p;
    int i;
    int n = 0; // 遍历，获取链表长度

    while(p){ // 只动p不动head
        ++n;
        p = p->next;
    }

    if(n==0){
        return head;
    }

    if(n==1){
        return head;
    }

    p = head;

    while(1){
        if(p&&p->next->next){
            p = p->next;
        }else{
            break;
        }
    }
    q = p->next;
    new = q;
    new_p = new;
    p->next = q->next;



    for(i=0;i<n-2;++i){
        p = head;
        // 循环用于定位到倒数第2个结点
        while(1){
            if(p->next->next!=NULL){
                p = p->next;
            }else{
                break;
            }
        }
        q = p->next;
        new_p->next = q;
        new_p = q;
        p->next = q->next;
        
    }

    new_p->next = head;// 执行n-2次后，只剩下一个head结点，直接赋给new_p->next
    head = new;

    return head;
    
}


```
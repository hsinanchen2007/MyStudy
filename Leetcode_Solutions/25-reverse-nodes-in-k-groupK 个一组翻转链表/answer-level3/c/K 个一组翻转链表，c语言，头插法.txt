### 解题思路
链表的头插法，每k个头插法一次，然后记录下这k个的尾巴用来链接下k个翻转的头。

### 代码

```c
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if(k == 1){
        return head;
    }
    struct ListNode *p = head,*q,*rear,*result,*r;//p是要逆转的节点,q是防止断链，头插法，head，rear是正在翻转的k个节点组成的链表的表头和表尾，r是上个翻转完的k个节点链表的表尾
    int n = 0;
    while(p){
        n++;
        p = p->next;
    }
    if(n/k == 0){
        return head;
    }else{
        p = head->next;        
        r = head;
        for(int i=0;i<k-1 && p;i++){
            q = p->next;
            p->next = head;
            head = p;
            p = q;
        }
        result = head;  //记录整个链表的表头，也就是翻转第一个k链表的表头
    }
    for(int i=1;i<n/k;i++){
        head = p;
        rear = head;
        p = p->next;
        for(int j=0;j<k-1 && p;j++){
            q = p->next;
            p->next = head;
            head = p;
            p = q;
        }
        r->next = head;
        r = rear;
    }
    r->next = p;
    return result;
}
```

```
//代码原理同上，只不过是一边遍历一边计数，遍历一次就行了。
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if(k == 1){
        return head;
    }
    struct ListNode *p = head,*q,*rear,*result,*r;//p是要逆转的节点,q是p的下一个节点防止断链，头插法，head，rear是正在翻转的k个节点组成的链表的表头和表尾，r是上个翻转完的k个节点链表的表尾
    int count = 1;
    p = head->next;     
    r = head;
    r->next = NULL;
    while(p && count/k != 1){
        q = p->next;
        p->next = head;
        head = p;
        p = q;
        count++;
    }
    result = head;  //记录整个链表的表头
    if(p){                    //翻转完第一组k链表还需要再翻转
        head = p;
        rear = head;
        p = p->next;
        rear->next = NULL;
        count++;
    }   
    while(p){  
        q = p->next;
        p->next = head;
        head = p;
        p = q;
        count++;
        if(count%k == 0){
            r->next = head;
            r = rear;
            head = p;
            rear = head;
            if(p){
                p = p->next;
                rear->next = NULL;
                count++;
            }
            
        }     
    }
    if(count%k != 0){  //最后一组不够k个，在逆转回来...

        p = head->next;
        head->next = NULL;
        while(p){
            q = p->next;
            p->next = head;
            head = p;
            p = q;
        }
        r->next = head;
    }
    return result;
}
```

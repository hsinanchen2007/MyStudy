
##### 方法一：迭代

更容易理解，效率更高

```C
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *res = NULL, *cur = head;
    while (cur){            //cur代表本次循环要处理的节点，此时head已提取至cur中
        head = head->next;  //head推进至下一个待处理节点
        cur->next = res;    //将新链表接在cur的后面，此时cur成为新链表的头
        res = cur;          //res也成为了新链表的头
        cur = head;         //cur提取旧链表中的head，进入下一轮处理
    }
    return res;
}
```
##### 方法二：递归

```C
struct ListNode* reverseList(struct ListNode* head){
    //当只有一个节点，它的反转就是本身
    if(!head || !head->next)  return head;
    //取出head节点，调用函数自身将head->next为头的链表反转，结果保存在res中
    struct ListNode *res = reverseList(head->next);
    //res的尾巴是head->next，所以需要将之前弹出的head接在此尾巴上
    head->next->next = head;
    head->next = NULL;
    return res;
}
```
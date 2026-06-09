### 解题思路
#### 首先了解迭代和递归的区别
迭代是在循环中，利用循环变量存储结果，作为下一次循环的初始条件。
递归则是在函数体中调用函数自身。

把反转的部分和未反转的部分看作是两条链表，更易理解

### 代码

```c
 // 迭代与普通循环的区别：参与循环的变量同时是保存结果的变量
 
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *s = NULL; // s用于返回已经反转的链表
    struct ListNode *p = head; // p用来遍历链表
    while(p){
        struct ListNode *nextTemp = p->next; //缓冲变量继承下一节点
        p->next = s; //当前遍历节点指向已反转的节点
        s = p; // s指向当前遍历的节点
        p = nextTemp; //p指向即将遍历的节点
    }
    return s;
}

// 递归法，循环调用遍历至链表表尾，将未反转链表表尾节点添加到反转链表表尾，最终指向NULL
// 注意链表长度小于2的情况
struct ListNode* reverseList(struct ListNode* head){
    if (head==NULL||head->next==NULL)    return head; // 遍历到表尾
    struct ListNode *p = reverseList(head->next); // 返回已反转部分的头指针
    head->next->next = head; // 反转未反转部分的表尾
    head->next = NULL; // 反转尾部指向NULL
    return p;
}

```
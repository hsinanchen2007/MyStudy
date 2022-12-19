### 解题思路
思路分析，伪码如下：
```
ListNode* oddEvenList(ListNode* head){
    if(head为NULL或一个节点或两个节点)
        return head;
    声明两个虚拟头结点：dummyOdd(0),dummyEven(0);
    while(循环遍历每个头结点){
        if(节点序号为奇数）
            插入到dummyOdd链表中（尾插法，只改变指针指向，不申请其他节点）
        else(节点序号为偶数)
            插入到dummyEven链表中（尾插法，只改变指针指向，不申请其他节点）

        将dummyEven链表尾节点置空，防止出现循环链表（如1->2->3->4->5->NULL）；
        将dummyOdd尾节点指向dummyEven头结点;

        return dummyOdd头结点的下一个节点；
    }
}
```

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        //特殊情况：NULL、一个节点、两个节点，则直接返回
        if(!head || !head->next || !head->next->next)
            return head;
            
        //声明虚拟头结点
        ListNode dummyOdd(0);
        //dummyOdd.next = head;
        auto p = &dummyOdd;

        ListNode dummyEven(0);
        //dummyEven.next = head->next;
        auto q = &dummyEven;

        int flag = 0;
        while(head){
            flag++;
            if(flag % 2 != 0){
                p->next = head;
                p = p->next;
            }
            else{
                q->next = head;
                q = q->next;
            }
            
            head = head->next;
        }
        q->next = NULL;//注意：必须加这句话，否则链表形成环，超出时间限制！！！
        p->next = dummyEven.next;

        return dummyOdd.next;

    }
};
```
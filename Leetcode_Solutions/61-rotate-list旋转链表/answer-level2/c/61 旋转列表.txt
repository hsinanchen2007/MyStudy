

![61 旋转链表.png](https://pic.leetcode-cn.com/a0b8db999cbe08883352dc635f1eccacbc8e92574d50192e7627071f4bf2f712-61%20%E6%97%8B%E8%BD%AC%E9%93%BE%E8%A1%A8.png)


思路：
1. 遍历链表，获取链表长度len
2. k = k % len （因为每隔len长度的替换都是一个轮回，因此对k取余数）
3. while(k) 循环k次，每次执行如下操作：

1. a结点先指向head结点，因为后面还需要用到head结点，用a结点代而遍历链表
2. for循环，执行 a = a->next 直到a结点指针指向倒数第2个链表结点
3. b = a->next  此时b指向最后一个链表结点， a->next = b-next ，即a结点指向NULL
4. b->next = head 此时b成为链表新的头结点，再将头结点b赋值给head指针
5. 循环k次，over！


```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    int len = 0;
    int i;
    struct ListNode* a;
    struct ListNode* b;
    a = head;

    if(!head){
        return head;
    }

    if(!head->next){
        return head;
    }

    while(a){
        ++len;
        a = a->next;
    }

    k = k % len;//取余数


    //循环k次
    while(k){
        a = head;
        for(i=0;i<len-2;i++){
            a = a->next;
        }
        b = a->next;
        a->next = b->next;
        b->next = head;
        head = b;


        k--;
    }
    return head;
}
```

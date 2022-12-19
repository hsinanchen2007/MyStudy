### 解题思路
![image.png](https://pic.leetcode-cn.com/0801b48c006ec13b9a459eb09491a13a1603b6754ba92cb3a3d96a82d2e1191b-image.png)

我的思路是首先获取链表中点，对链表进行断链，然后将第二条链表进行翻转，采用的是迭代的思想，当然，递归思想也可以对链表进行翻转
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


void reorderList(struct ListNode* head){
    if( !head || !(head->next) ){
        return;
    }
    //获取中间节点
    struct ListNode* slowp = head;
    struct ListNode* fastp = head;
    while( fastp && fastp->next )
    {
        slowp = slowp->next;
        fastp = fastp->next->next;
    }

    //获取第二个链表头结点-----即中点后面部分
    struct ListNode* cur = slowp->next;     //无论奇数还是偶数个节点
    //进行断链，区分第一和第二链表
    slowp->next = NULL;

    struct ListNode* post = NULL;
    struct ListNode* pre = NULL;
    //翻转第二个链表
    while(cur)
    {
        //获取下一个节点
        post = cur->next;
        //切断该节点与下一个节点的连接,并将该节点后面连接上一个节点
        cur->next = pre;
        //保存当前节点位置，方便翻转时切换连接
        pre = cur;
        //指向下一个节点
        cur = post;
    }//此时pre是翻转后的头节点指针
    //合并节点
    slowp = head;
    fastp = head->next;
    while(pre)
    {
        cur = pre;
        pre = cur->next;
        slowp->next = cur;
        cur->next = fastp;
        slowp = fastp;
        fastp = fastp->next;
    }
}
```
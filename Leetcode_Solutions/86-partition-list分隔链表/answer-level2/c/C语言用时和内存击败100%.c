### 解题思路

![list.png](https://pic.leetcode-cn.com/de540ffc869ddced842f9640edd0880c3f926463e65b2569548f93c5d66fdfb2-list.png)
利用数组排序的插入法，往后寻找比X值得结点，插入到前面
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    if(head==NULL||head->next==NULL)
        return head;
    struct ListNode* tou=(struct ListNode*)malloc(sizeof(struct ListNode));//自行设置头结点，避免特殊处理头结点，例如第一个数就大于x
    tou->next=head;
    struct ListNode* p=tou,*s,*pre;
    while(p->next&&p->next->val<x)
        p=p->next;//p用于指向前面小于X的最后一个结点进行插入，例如1，2，4，3，5，2，4，2，p指向第二个结点，p->val=2;
    int flag;//flag用于标志，如果往后遍历没有发现比X小的结点，则break
    while(1){
        pre=p;
        s=pre->next;//s用于往后找比x小的结点，pre用于指向s的前驱
        flag=0;
        while(s){
            if(s->val<x){
                flag=1;
                break;
            }
            pre=s;
            s=s->next;
        }
        if(flag==0)
            break;
        else{
            //
            pre->next=s->next;//把s结点拿出来插入到p后面
            s->next=p->next;
            p->next=s;
            //当插入一个结点之后，p就往后一位
            p=p->next;
        }
    }
    return tou->next;
}
```
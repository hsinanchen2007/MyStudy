### 解题思路
![图片.png](https://pic.leetcode-cn.com/33523abdd1d4f8b340227ddf0c398a12c581f99b0e59c9173687390713365fd1-%E5%9B%BE%E7%89%87.png)

第一步：确定有无圆环
第二部：查找环结点，及圆环开始的地方

第一步是快慢指针，p走一步,q走两步，如果有环必然相遇,但这时相遇的那个点不是环结点。
第二部，从头结点开始到环结点的距离 等于 从相遇处开始到环结点的距离。只要不断next，就能找到
最终答案。
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(head==NULL){
        return head;
    }
    struct ListNode *p=head;
    struct ListNode *q=head;
    struct ListNode *t1=head;
    struct ListNode *t2=head;
    p=p->next;
    if(p==NULL){
        return NULL;
    }
    q=q->next->next;
    int flag=0;
    while(p!=NULL&&q!=NULL){
        if(p==q){
            t2=p;
            flag=1;
            break;
        }
        p=p->next;
        if(q->next==NULL){
            return NULL;
        }
        q=q->next->next;
    }
    if(flag==0){
        return NULL;
    }else{
        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;
        }
        return t1;
    }
}
```
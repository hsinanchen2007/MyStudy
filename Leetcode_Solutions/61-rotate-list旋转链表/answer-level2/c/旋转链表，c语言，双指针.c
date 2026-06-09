### 解题思路
先看看链表长度count和k谁大，如果是k大那就只用翻转k%count次。然后双指针，让p先走k次，然后q从头在和p一块往后遍历，两者相差k，当p是链表最后一个非空节点时，q是新链表的表尾，q->next是新链表的表头

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head == NULL){
        return head;
    }
    struct ListNode *p=head,*q;
    int count = 0;
    while(p && count<=k){   //判断链表长度和k哪个大,如果链表长度大那么最后count等于k+1
        count++;
        p = p->next;
    }
    if(count <= k){ 
        k = k%count;
        if(k == 0){                        //k是链表长度的整数倍，不用旋转
            return head;
        }
    }
    p = head;
    for(int i=0;i<k;i++){
        p = p->next;
    }
    q = head;
    while(p->next){    //双指针，两者相差k个，当p是最后一个时，q->next应该是翻转后链表的表头，q是表尾
        p = p->next;
        q = q->next;
    }
    p->next = head;
    p = q->next;
    q->next = NULL;
    return p;
}
```
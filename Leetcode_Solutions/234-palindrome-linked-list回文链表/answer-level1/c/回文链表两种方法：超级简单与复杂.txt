一：这是一种非常简单的做法，只需要你学过数组即可，r当然如果想满足题目中说的时间是O(n)，空间为O(1)，可以**参考第二种做法**，也很有意思。
    1.回文链表即后半段和前半段反序相同，比如**12344321， 123321**这样子，这里有一点恶心在于这是一个链表，首先长度也不知道，然后单链表也无法后面从前遍历，那么很容易想到先遍历一遍然后存入数组，则很好操作。
    2。开一个足够大的数组，**7w+**，然后遍历一遍链表，记录长度，保存数据，然后for一遍，用第一个元素和倒数第一个元素比较，第二个和倒数第二个比较，不相等就返回false即可。代码如下：

```C
int q[70000];
bool isPalindrome(struct ListNode* head){
    struct ListNode* p = head;
    int len = 0;
    while(p){
        len++;
        q[len] = p->val;
        p = p->next;
    }
    for(int i = 1; i <= len/2; i++){
        if(q[i] != q[len-i+1]) return false;
    }
    return true;
}
```


### 解题思路
二：链表反转（满足题目要求的时间是O(n)，空间为O(1)）；
    1：顾名思义就是把链表反过来，因为如果是单向链表会很难判断回文（n方），比如1->2->3->2->1，那么就将其变成1<-2<-3->2->1,再比如1->2->2->1，那么就变成1<-2->2->1，然后从中间向两边遍历就十分简单。
    2：首先要有三个变量来记录三个节点，所以索性n在3以下的全部特判掉，只考虑大于三的情况，由于贴不上图只能干讲了，有兴趣的在纸上画张图就很好理解了，比如对于1 2 3 2 1，首先三个指针q p r，分别指向1 2 3，然后将1的指针置为空（不做会可能h留下隐患，比如循环指针），然后将2的指针指向1，即p->next = q,这时变成了1<-2 3->2->1，然后让q = p, p = r, r = r->next。f然后循环做即可。
```C
1->2->3->2->1 --> 1 2->3->2->1 --> 1<-2 3->2->1 //链表变化
                  q->next = NULL    p->next = q  //相应操作
q  p  r           q qp  r          q  p r       //指针变化

--> 1<-2 3-> 2->1  --> 1<-2 3->2->1
    q = p, p = r       r = r->next
    q qp pr            q qp pr r

```
如此循环就可了，当然除了这个还有一些细节需要去做，比如反转之后如何比较，反转之后q的位置，即前半段从哪里开始，后半段从哪里开始，我在代码中有标明，在草稿纸上画画很容易理解。
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool isPalindrome(struct ListNode* head){
    if(head == NULL) return true;
    int len = 0;
    struct ListNode *p = head;
    while(p){
        len++;
        p = p->next;
    }
    if(len == 1) return true;
    if(len == 2){
        if(head->val == head->next->val) return true;
        else return false;
    }
    if(len == 3){
        if(head->next->next->val == head ->val) return true;
        else return false;
    }
    int tmp = (len-1)/2, flag = 0;
    if(len%2 == 1) flag = 1;
    len = (len+1)/2;
    p = head;
    while(len){
        head = head->next;
        len--;
    }
    struct ListNode *q = p, *r = p->next->next;
    p = p->next;
    q->next = NULL;
    while(tmp){
        p->next = q;
        q = p;
        p = r;
        r = r->next;
        tmp--;
    }
    if(flag == 1) q = q->next;
    while(head){
        if(q->val != head->val) return false;
        q = q->next, head = head->next;
    }
    return true;
}
```
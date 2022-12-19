这道题怎么题解那么少？那么我来分享一下我的代码~

主要步骤分为两步：
1. 构建一个新的链表，除了其中每个结点的随机指针`h1->random==NULL`都为`NULL`，和原链表并无其他差别；
2. 新链表构建好之后，我们利用计数器index，依次遍历新链表，对每个结点的随机指针进行赋值。

[我的其他笔记](https://blog.csdn.net/AuthurWhywat)，欢迎大家前来指出我的不足~
```
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct TreeNode *next;
 *     struct TreeNode *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
	if(!head) return NULL;

    /*使用next将整个链表构建起来*/
    
    struct Node *head1 = (struct Node *)malloc(sizeof(struct Node));
    head1->val = head->val;
    head1->next = NULL;
    head1->random = NULL;

    struct Node* h = head, * h1 = head1;

    while(h->next){
        h = h->next;
        struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
        temp->val = h->val;
        temp->next = NULL;
        temp->random = NULL;
        
        h1->next = temp;
        h1 = h1->next;
    }
    /*处理那个随机指针*/

    h = head; h1 = head1; 
    while(h){
        if(!h) break;

        int index=0;
        struct Node * cur=head, * cur1=head1;

        if(h->random){
            while(cur && cur!=h->random){
                index++;
                cur = cur->next;
            }
            while(index){
                index--;
                cur1 = cur1->next;
            }
            h1->random = cur1;
        }
        else h1->random = NULL;
        
        h = h->next;
        h1 = h1->next;
    }
    return head1;
}
```

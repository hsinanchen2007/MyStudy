### 解题思路
![image.png](https://pic.leetcode-cn.com/2e5fe7d9bdb688df2c0d2a981f67b04bd527590e532efde837e5da0c76856f75-image.png)
常规解法，主要是展示C写法，为C做贡献


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
    if(head == NULL || head -> next == NULL) return head;

    //找到链表中心结点
    struct ListNode *slow, *fast, *newHead, *p, *r;
    slow = fast = head;
    newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    //拆成两个链表
    p = slow -> next;
    slow -> next = NULL;
    //头插法反转第二个链表
    newHead -> next = NULL;
    while(p != NULL){
        r = p -> next;
        p ->next = newHead -> next;
        newHead -> next = p;
        p = r;
    }
    //合并两个链表
    p = head;
    fast = newHead -> next;
    while(fast != NULL){
        r = fast -> next;
        fast -> next = p -> next;
        p -> next = fast;
        p = fast -> next;
        fast = r;
    }
    free(newHead);
    return head;
}

```
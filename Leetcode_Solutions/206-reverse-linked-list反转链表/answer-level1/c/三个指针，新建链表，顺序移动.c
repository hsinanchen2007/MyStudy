### 解题思路
此处撰写解题思路
关键在与指针的使用。
通过pre和cur分别表示前一个节点和当前节点，循环整个链表，直到末尾的NULL为止。

第0步：
[1]->[2]->[3]->...

第1步：
[1]->NULL  [2]->[3]->...
newHead    cur

第2步：
[1]->NULL  [2]->[3]->...
newHead    pre  cur            //pre=cur; cur=cur->next;

第3步：
[2]->[1]->NULL  [3]->...
pre  newHead    cur            //pre->next =newHead;

第4步：
[2]->[1]->NULL  [3]->...
newHead         cur            //newHead = pre;

重复2~4步，直至原链表尾

【注意】
保护异常场景，空链表，链表节点为1
为了方便理解，新定义三个指针；可以不定义cur，而是使用原题目的head指针，以节约一个指针空间。


【代码】
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* pre;
    struct ListNode* cur;
    struct ListNode* newHead;

    if (head == NULL) {
        return head;
    }

    newHead = head;
    cur = head->next;
    newHead->next = NULL;
    while (cur != NULL) {
        pre = cur;
        cur = cur->next;
        pre->next = newHead;
        newHead = pre;
    }

    return newHead;
}
```
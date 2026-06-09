### 解题思路
算出正向走到链表哪里，然后删除掉那个节点就完事
![未命名图片.png](https://pic.leetcode-cn.com/c7fda5535e40abb7bd9d05b00122e92a52ddaf2a31e1d96cf151e9eb606ba5d5-%E6%9C%AA%E5%91%BD%E5%90%8D%E5%9B%BE%E7%89%87.png)


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int len = 0;
    int step = 0;
    struct ListNode * tmp = head;
    struct ListNode * res = head;
    while (tmp != NULL) {
        len++;
        tmp = tmp->next;
    }
    if (len == 1) return NULL;
    step = len - n;
    if (step == 0) res = head->next;
    for (int i = 0; i < step - 1; i++) 
        head = head->next;
    //printf("%d ", head->val);
    head->next = head->next->next;
    return res;


}
```
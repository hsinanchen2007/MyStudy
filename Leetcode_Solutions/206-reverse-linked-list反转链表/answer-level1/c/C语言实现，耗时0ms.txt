### 解题思路

需要三个指针，

- 一个是head, 记录后一个位置
- 一个是cur，记录当前的位置
- 一个是res，表示上一个位置

最开始，cur=head, res=NULL, 表示cur在第一个位置，res是最后的NULL

然后head往后, `head = head->next;`

将当前的后一个位置指向到前一个位置 `cur->next = res;`

然后依次将res和cur往后移动`res =cur; cur=head;`

最后耗时0ms

![image.png](https://pic.leetcode-cn.com/dfc718a882b8eebab507886b2710d9b11b20cc077cf1236a02b8bc2a27b17840-image.png)


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){

    struct ListNode *res = NULL, *cur = head;
    while (head != NULL){
        head = head->next;
        cur->next = res;
        res= cur;
        cur = head;

    }
    return res;
}
```
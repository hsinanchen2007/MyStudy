### 解题思路
1、定义一个守卫节点为当前输入的head的前置节点
2、移动指针到需要倒置的位置
3、头插法即可完成旋转链表
![image.png](https://pic.leetcode-cn.com/7d1fb911045f366cb6a1916a97600f689f1bb20900dbf193046f1837451b635c-image.png)

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    struct ListNode reverHead = {0};
    reverHead.next = head;

    struct ListNode *pre = &reverHead;
    struct ListNode *cur = reverHead.next;
    int index = 0;
    while (index < m - 1) {
        cur = cur->next;
        pre = pre->next;
        index++;
    }
    for (int i = 0; i < n - m; i++) {
        struct ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        tmp->next = pre->next;
        pre->next = tmp;   
    }
    return reverHead.next;
}
```
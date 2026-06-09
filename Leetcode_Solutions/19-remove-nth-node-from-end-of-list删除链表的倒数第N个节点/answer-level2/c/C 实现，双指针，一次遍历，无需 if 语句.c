![2019-10-01_05-52.png](https://pic.leetcode-cn.com/475a061251e40bb754d627ab9c3e1ff9ae1d21276a01b7fdc352d397e16711ca-2019-10-01_05-52.png)

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    // 使用了 Linus Torvalds 的魔法
    // 无需使用 if 语句区分移除的是否是头节点
    struct ListNode ** cur = &head; // 第一个指针
    struct ListNode ** fol = &head; // 间隔为 n 的跟随指针
    // cur 先走 n 步
    for (; n > 0; n--)
        cur = &((*cur)->next);
    // 两指针同时移动
    while (*cur) {
        cur = &((*cur)->next);
        fol = &((*fol)->next);
    }
    // 记录待移除节点
    struct ListNode * tmp = *fol;
    // 跨过待移除节点
    *fol = (*fol)->next;
    free(tmp);
    return head;
}
```

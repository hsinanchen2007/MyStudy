### 解题思路
菜鸡思路，一个`cur`向前跑，同时`cur_pos`记录跑的位置，然后每次用`prev=head`从头跑到`prev_pos=cur_pos-1`看是不是循环。
+ basecase:空表或单独头节点没有`next域`(还有单个节点连自身的操作)
![image.png](https://pic.leetcode-cn.com/c90da1ef2f4b1ebf3357d6eba7d56caf2ad21a1691aa2936b6fc95b0780a84e8-image.png)

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (!head || !head->next) return false;  // 一个一定没有(还有可能一个指向自己))
    struct ListNode *prev, *cur = head->next;  // cur是存在的head!=null
    int cur_pos = 1, prev_pos;
    while (cur) {
        cur = cur->next;  // 先走一步
        cur_pos++;
        /* 从头往后追 */
        prev_pos = 0;
        prev = head;
        while (prev_pos < cur_pos) {
            if (cur == prev) return true;  // 指针相等
            prev = prev->next;
            prev_pos++;
        }
    }
    return false;
}
```

时间复杂度：应该是O($n^2$)吧，不然怎么可能被95%用户打败？😫
空间：O(1)
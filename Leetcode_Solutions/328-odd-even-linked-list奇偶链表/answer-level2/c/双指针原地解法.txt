### 解题思路
奇数双指针依次后移；
 1、指针evenHead指向偶数节点头，保持不动，插入的奇数尾永远指向偶数节点头；
 2、偶数指针逐步后移，链接剩余的奇数链
![image.png](https://pic.leetcode-cn.com/d9a7628400c14fd3ff20abaf8f1db622d01ac34295ce6e46f2637dbfdc5270a7-image.png)

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 /*思路：奇数双指针依次后移；
 1、指针evenHead指向偶数节点头，保持不动，插入的奇数尾永远指向偶数节点头；
 2、偶数指针逐步后移，链接剩余的奇数链*/
struct ListNode* oddEvenList(struct ListNode* head)
{
    struct ListNode *p, *q, *oddTemp, *evenHead, *evenTemp;
    if (head == NULL || head->next == NULL) {
        return head;
    }
    evenHead = head->next; // 偶数头节点，保持不动
    evenTemp = evenHead;
    p = head;
    q = p->next->next;
    while (q) {
        if(q->next) {
            oddTemp = q->next->next; // 暂存下一个奇数节点
        } else {
            oddTemp = NULL;
        }
        p->next = q;
        evenTemp->next = q->next;
        q->next = evenHead;
        p = p->next;
        evenTemp = evenTemp->next;
        q = oddTemp;
    }
    return head;
}
```
### 解题思路
1. 因为是单链表，进行遍历时，无法向后再进行返回，所以不能移动到链表尾部再返回，而且增加了时间复杂度，多移动了k次；
2. 链表从1开始计数，知道总的链表长度`n`，给定倒数第`k`个，那么链表移动`n-k`次。
3. 在进行计算链表总长度时，由于再`nodesize=nodesize->next;`最后一个链表再向后移动一个，并且n多加了一次之后再跳出循环，所以n从0开始计数。
4. 最后返回头指针。

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) 
    {
        ListNode *nodesize=head;
        int size;
        int n=0;
        while (nodesize)
        {
            nodesize=nodesize->next;
            ++n;
        }
        size = n-k;
        while (head && size)
        {
            head=head->next;
            --size;
        }
        return head;
    }
};
```
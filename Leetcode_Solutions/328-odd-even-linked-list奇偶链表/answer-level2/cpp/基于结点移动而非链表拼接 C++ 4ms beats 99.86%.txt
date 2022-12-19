### 解题思路
1. 当链表含0、1、2个元素时，不需要操作，直接返回。
2. 当链表含两个元素以上时：可以这么理解变换步骤：
以[1,2,3,4,5,6,7]为例：

1. pivot指向1：将3“剪切”，插入到1后；然后pivot指向刚刚插入的3，因为下一个数字（5），将插入到3后。
2. pivot指向3：将5“剪切”，插入到3后；
3. pivot指向5：将7“剪切”，插入到5后。



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
    ListNode *oddEvenList(ListNode *head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }
        ListNode *pivot = head;//要插入到pivot之后
        ListNode *pre;//始终指向cur的前驱节点
        ListNode *cur = head; //实际上为两步两步走的指针，cur所指向的每一个结点，都插到pivot之后
        ListNode *next = cur->next;
        while (next && next->next) {
            cur = next->next;
            pre = next;
            next = cur->next;

            pre->next = cur->next;//cut
            cur->next = pivot->next;//paste1
            pivot->next = cur;//paste2
            pivot = cur;
        }
        return head;
    }
};
```
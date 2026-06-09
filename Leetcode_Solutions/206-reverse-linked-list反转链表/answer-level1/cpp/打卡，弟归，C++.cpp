如果要反转链表，只考虑两个节点，我们仅需要将下一个节点的next指针指向当前节点即可。
然而，这会破坏链表的顺序，改变了next指针之后，我们将无从得知其本来指向的元素是什么。

于是，自然想到两种方法:
1. 迭代。定义一个tmp指针，暂时记录下一个节点的next指针指向哪一个节点。
2. 递归。我们从后向前地改变两两之间的顺序。定义一个reverse函数，该函数的返回值就是当前节点。
核心代码是:
```c++
reverse(now->next)->next = now;
```
在执行该步操作时，由递归特性可知，now节点之后的节点都完成了翻转，解决了上面的问题。

时间复杂度分析: 迭代和递归都是O(n)。
空间复杂度分析: 迭代为O(1)，但是递归需要额外的栈空间，其空间复杂度为O(n)。

附上代码:

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* newHead;
    ListNode* reverse(ListNode* now)
    {
        if (now->next == NULL)
        {
            newHead = now;
            return now;
        }
        reverse(now->next)->next = now;
        return now;
    }

    ListNode* reverseList(ListNode* head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        reverse(head)->next = NULL;
        return newHead;
    }
};
```

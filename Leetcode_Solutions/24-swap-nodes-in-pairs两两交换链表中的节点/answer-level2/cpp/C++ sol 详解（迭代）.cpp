### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7.9 MB, 在所有 C++ 提交中击败了100.00%的用户

//

1. 由于是两两交换的问题，我们可以把模型稍微简化一下，首先设定一个newNode作为哨兵节点。
2. 然后设定curr节点，通过它我们就能得到需要交换的两个节点，分别是 curr 和 curr->next。我们将它们分别命名为firstNode, secondNode。
3. 现在就显现出哨兵节点（newNode，prev 指针是它的替身）的作用了，我们将 secondNode 赋给 prev->next。完成这一步后需要注意，还不能更新secondNode->next，因为我们要把secondNode->next先赋给firstNode->next。
4. 以上结束后，将firstNode赋给secondNode->next就完成了两两节点的交换。
5. 接下来的任务很重要，先要更新prev，显然这里变成了firstNode。然后需要更新下一组需要两两交换的节点，将curr更新为firstNode->next即可。（还记得这里的firstNode->next是谁吗？如果完全理解这个问题的话就不难看出，它就是最开始的secondNode->next，也就是最开始的firstNode->next->next）

以上为迭代方法处理两两节点交换的问题，但其实这个问题可以扩展成交换链表中每k个节点，在本问题中，k=2。如果扩展此问题，这样的迭代法就不太适用了（思考为何？），可以考虑使用倒序节点+递归的方法来实现，具体可以看我这篇详解：

[https://leetcode-cn.com/problems/reverse-nodes-in-k-group/solution/c-sol-1-diao-huan-shun-xu-di-gui-by-silverblg/](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/solution/c-sol-1-diao-huan-shun-xu-di-gui-by-silverblg/)


如果能把两两交换、以及前k个交换的方法都掌握，那么这类链表问题就不在话下了。

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
    ListNode* swapPairs(ListNode* head) {
        ListNode newNode(-1);
        newNode.next = head;

        ListNode* prev = &newNode;
        ListNode* curr = head;

        while (curr && curr->next) {
            ListNode* firstNode = curr;
            ListNode* secondNode = curr->next;

            prev->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;

            prev = firstNode;
            curr = firstNode->next;
        }

        return newNode.next;
    }
};
```
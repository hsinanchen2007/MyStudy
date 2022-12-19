### 解题思路
本题的思路比较简单，首先拿到题目后，我们看需要找到的关键点：

1. 删除所有的重复元素
2. 链表是排了序的

如果只有第一个条件，那么我们需要使用缓存来对遍历的数据进行保存，这样在遍历到后面的时候还能和前面的元素进行比较；但是有一个链表有序的条件，这样我们不用多余的缓存结构，只需要保存找到的第一个不同元素即可，然后再继续遍历和其对比。

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *comparedNode = head;
        while (comparedNode != NULL) {
            // compare the next with the comparedNode
            ListNode *nextNode = comparedNode->next;
            while (nextNode != NULL && nextNode->val == comparedNode->val) {
                // remove the nextNode
                ListNode *postNode = nextNode->next;
                comparedNode->next = postNode;
                delete nextNode;
                nextNode = postNode;
            }
            comparedNode = comparedNode->next;
        }
        return head;
    }
};
```
### 解题思路

1. 说实话相较于数组层面的插入排序，这个不好理解。插入排序的关键在于查找，找到 <= 当前元素值的最后一个位置，然后在此位置之后（不能是之前）插入元素。
2. 设置哨兵节点至关重要，特别是每次循环时从哨兵节点往后找到比curr正好小的那个节点这一步。
3. 不太好理解，需要画一画，加深记忆。

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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode newNode(-1);
        newNode.next = head;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr) {
            if (prev->val > curr->val) {
                ListNode* tmpNode = &newNode;
                while (tmpNode->next->val <= curr->val) tmpNode = tmpNode->next;
                prev->next = curr->next;
                curr->next = tmpNode->next;
                tmpNode->next = curr;

                curr = prev->next;
            } else {
                prev = prev->next;
                curr = curr->next;
            }
        }

        return newNode.next;
    }
};

```
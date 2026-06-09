### 解题思路
此处撰写解题思路
设置快指针和慢指针，让两个指针间隔k而移动
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* temp = head;//我们以head为快指针，temp为慢指针

        if (NULL == head)
            return head;

        while (head && k--) head = head->next;//head快指针先移动k个间隔
        while (head) {head = head->next; temp = temp->next;}//然后快慢指针始终间隔k而移动

        return temp;//最后返回慢指针就可以了
    }
};
```
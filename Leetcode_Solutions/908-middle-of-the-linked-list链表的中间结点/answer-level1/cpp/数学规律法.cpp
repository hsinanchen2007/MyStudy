### 解题思路
此处撰写解题思路
数学规律法，根据遍历过的节点总数的奇偶性来判断结果指针是否移动

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
    ListNode* middleNode(ListNode* head) {
        if (!head) return NULL;
        int iCout = 1;
        ListNode* cur = head;
        ListNode* midCur = head;
        while (cur->next)
        {
            iCout++;
            cur = cur->next;
            if (iCout%2==0) midCur = midCur->next;
        }
        return midCur;
    }
};
```
### 解题思路
暴力法，使用set来存之前的节点，如果发现重复，则有环
![image.png](https://pic.leetcode-cn.com/9f9f2a4ad911bd091489dd10025f7db71322acdfec21e1142c6f59f4b842a532-image.png)

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
    ListNode *detectCycle(ListNode *head) {
        set<ListNode *> s;
        int index = 0;
        while (head) {
            if (s.find(head)!=s.end()) {
                break;
            }
            s.insert(head);
            index++;
            head = head->next;
        }
        return head;
    }
};
```
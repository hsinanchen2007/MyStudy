### 解题思路
由于本题从1开始计数，即链表的尾节点是倒数第1个节点。因此，快指针`rp`只需先走`k-1`步。较常规双指针少走一步。
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
        ListNode *lp = head, *rp = head;
        while (rp->next != NULL) {
            rp = rp->next;// 结束时，rp是最后一个节点，而非NULL
            if (k > 1) {
                k--;
            } else {
                lp = lp->next;
            }
        }
        return lp;
        
    }
};
```

常规的，`rp`先走`k`，最终`rp`指向`NULL`
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
        ListNode *lp = head, *rp = head;
        while (rp != NULL) {
            rp = rp->next;// 结束时，rp是最后一个节点，而非NULL
            if (k > 0) {
                k--;
            } else {
                lp = lp->next;
            }
        }
        return lp;
        
    }
};
```

![qcode.png](https://pic.leetcode-cn.com/ed39a6a544a01e32305e1316da9921f2288a0822501da45abee0a76ea24dd4dd-qcode.png)

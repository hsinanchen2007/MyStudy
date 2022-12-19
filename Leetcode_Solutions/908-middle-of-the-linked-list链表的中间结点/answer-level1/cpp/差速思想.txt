### 解题思路
两个指针，指针一每遍历两次指针二遍历一次，达到指针二始终在指针一一半的位置，遍历结束返回指针二即可
执行用时 : 0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 : 8 MB, 在所有 C++ 提交中击败了100.00%的用户
量子计算机？
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
        ListNode* p = head;
        ListNode* m = head;
        int i = 1;
        while(p) {
            p = p->next;
            if(i%2==0){
                m = m->next;
            }
            i++;
        }
        return m;
    }
};
```
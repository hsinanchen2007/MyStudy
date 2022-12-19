执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.5 MB, 在所有 C++ 提交中击败了9.22%的用户
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
    int getDecimalValue(ListNode* head) {
        int sum = 0;

        while (head -> next){
            sum = (sum + head -> val) * 2;
            head = head -> next;
        }
        sum += head -> val;
        return sum;
    }
};
```
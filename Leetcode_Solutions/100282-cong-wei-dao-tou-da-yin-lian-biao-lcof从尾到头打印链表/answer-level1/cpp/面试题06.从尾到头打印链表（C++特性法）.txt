### 解题思路
核心思路：遍历链表，并把节点中的数插入vector的头部（vector::insert(vector::begin(),val)）
执行用时 :72 ms, 在所有 C++ 提交中击败了12.65%的用户
内存消耗 :10.2 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    vector<int> reversePrint(ListNode* head) {
        vector<int>result;
        auto i=head;
        while(i!=NULL){
            result.insert(result.begin(),i->val);
            i=i->next;
        }
        return result;
    }
};
```
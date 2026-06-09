### 解题思路
1. 先求出链表总长度
2. 通过总长度和k求出每个子链的最低长度和长度多一个的子链表
3. 遍历链表分割链表

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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> vec(k, nullptr);
        int count = 0;
        // 遍历链表，通过count计数求链表长度
        auto p = root;
        while (p != nullptr) {
            p = p->next;
            count++;
        }
        // len存储每个分割后的链表的最低长度
        // cc分割后长度是最低长度+1的链表个数
        auto len = count / k;
        auto cc = count % k;
        for (auto &vp : vec) {
            vp = root;
            auto p = root;
            // 直接将前cc个子串多分一个
            // 将p从当前剩余链表的头跳到尾巴节点上
            auto tlen = len + (cc-- > 0 ? 1 : 0) - 1;
            while (tlen-- > 0) {
                p = p->next;
            }
            if (p != nullptr) {
                // 分割链表
                root = p->next;
                p->next = nullptr;
            }
        } 
        return vec;
    }
};
```
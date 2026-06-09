### 解题思路
> 执行用时 :16 ms, 在所有 C++ 提交中击败了9.84% 的用户
> 内存消耗 :7.3 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        vector<int> v;
        int count = 0;
        ListNode* l = head;
        while(l)
        {
            v.push_back(l->val);
            l = l->next;
            count++;
        }

        k = k % count;
        reverse(v.begin(),v.end());
        reverse(&v[0] , &v[k]);
        reverse(&v[k] , &v[count]);

        l = head;
        int i = 0;
        while(l)
        {
            l->val = v[i++];
            l = l->next;
        }
        return head;

    }
};
```
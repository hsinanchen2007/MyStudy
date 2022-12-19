### 解题思路
遍历链表把节点值放到数组中，剩下的就是easy了

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
    int getDecimalValue(ListNode* head) {
        vector<int> v;
        ListNode* p = head;//保护输入
        //链表遍历
        while(p != NULL)
        {
            v.push_back(p->val);
            p = p->next;
        }

        int ret = 0;
        for(int i = 0;i < v.size();i++)
        {
            ret = ret*2 + v[i];
        }

        return ret;
    }
};
```
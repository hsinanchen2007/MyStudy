### 解题思路
![743b4bb6bf06cce02ccd927611909fe.png](https://pic.leetcode-cn.com/b27c676594514dc783273c24fbb4504410fa0341b048ddb73950a12c73161d68-743b4bb6bf06cce02ccd927611909fe.png)
此处撰写解题思路

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
        vector<int> ivec;
        while(head != NULL)
        {
            ivec.push_back(head->val);
            head = head->next;
        }
        vector<int> res;
        for(int i = ivec.size()-1; i >=0; --i)
        {
            res.push_back(ivec[i]);
        }
        return res;

    }
};
```
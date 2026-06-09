### 解题思路
先利用vector数组将链表内的数值存储，就和739题：每日温度类似了。维护一个单调递减栈，栈内保存的是元素在数组内的位置，当栈顶元素对应的值小于当前元素时，栈顶元素对应的答案就是当前元素。
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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* pre = head;
        vector<int> vals;
        while(pre != NULL)
        {
            vals.push_back(pre -> val);
            pre = pre -> next;
        } 
        int len = vals.size(), i = 0;
        vector<int> ans(len, 0);  //结果数组，首先都初始化为0
        stack<int> stacks;  //单调递减栈
        while(i < len)
        {
            if(stacks.size() && vals[stacks.top()] < vals[i])
            {
                ans[stacks.top()] = vals[i];
                stacks.pop(); 
            }
            else
                stacks.push(i ++);
        }
        return ans;
    }
};
```
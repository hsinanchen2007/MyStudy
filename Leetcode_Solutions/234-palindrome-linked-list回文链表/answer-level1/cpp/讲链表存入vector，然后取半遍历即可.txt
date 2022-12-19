##思路如下
放入vector，然后遍历即可，很容易

## 代码

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
    bool isPalindrome(ListNode* head) {
        vector<int> listvalue;
        while(NULL != head)
        {
            listvalue.push_back(head->val);
            head = head->next;
        }
        int lenth = listvalue.size();

        for(int i=0;i<lenth/2;i++)
        {
            if(listvalue[i] != listvalue[lenth-i-1])
                return false;
        }
        return true;

    }
};
```

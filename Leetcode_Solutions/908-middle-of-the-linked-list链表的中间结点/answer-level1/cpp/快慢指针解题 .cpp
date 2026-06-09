### 解题思路
此处撰写解题思路
这个题简单，也来分享下吧。
基本思路就是往后遍历，计算当前遍历到的长度，根据长度调整当前的中位数指针。
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
        if(head==nullptr)
        {
            return nullptr;
        }
        int nLength=1;
        ListNode* pMiddle=head;
        ListNode* pSearch=head;
        while(pSearch!=nullptr)
        {
            if(nLength%2==0)
            {
                pMiddle=pMiddle->next;
            }
            pSearch=pSearch->next;
            ++nLength;
        }
        return pMiddle;
    }
};
```
复杂度分析：
o(n)
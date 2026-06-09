### 解题思路
此处撰写解题思路
从head开始遍历整个list把所有node存放到vector中，然后调用algorihm库中反转函数reverse进行逆序即可。
因为用了外部存储（vector）所以空间复杂度是O(n),时间复杂度用reverse实现迭代器两两交换iter_swap(first++,--end)为O(n/2)

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
#include <algorithm>

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ResultVec;
        if(head)
        {
            ResultVec.push_back(head->val);
            ListNode* TmpNode = head;
            while(TmpNode->next)
            {
                ResultVec.push_back(TmpNode->next->val) ;
                TmpNode = TmpNode->next;
            }
            reverse(ResultVec.begin(),ResultVec.end());
        }
        
        return ResultVec;
    }

    
};
```
### 解题思路
遍历的时候把指针存放到向量中，然后直接按照向量索引删除节点即可，注意删除头尾节点边界就行了。
做题而已，也不用释放指针是吧。。。

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> plist;
        ListNode *ptr = head;
        while (ptr)
        {
            plist.push_back(ptr);
            ptr = ptr->next;
        }
        if (plist.size() == 1)  return NULL;
        if ( n == 1)    plist[plist.size()-2]->next = NULL;
        else if (n == plist.size()) return head->next;
        else    plist[plist.size()-n-1]->next = plist[plist.size()-n+1];
        return head;
    }
};
```
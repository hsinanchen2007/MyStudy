### 解题思路
这个反转一开始转的我头昏眼花，直到看到一个视频我才明白了链接如下https://www.bilibili.com/video/av49762694?from=search&seid=3952211739984326978
递归的还没整明白，再见各位！

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
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return nullptr;
        }
        ListNode* pre = NULL;
        ListNode* next = NULL;
        ListNode* cur = head;
        while(cur != nullptr){
            next= cur->next;
            cur->next= pre;
            pre = cur;
            cur = next;
        }
        head = pre;
        return head;
    }

};
```


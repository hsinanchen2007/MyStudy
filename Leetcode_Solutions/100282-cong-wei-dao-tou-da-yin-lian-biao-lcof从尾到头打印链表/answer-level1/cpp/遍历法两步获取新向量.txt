### 解题思路
1. 获取链表长度（由于系统没有提供获取长度的函数）【遍历】；
2. 创建等长向量，并再次【遍历】，反向将数值加入。

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
        int length;
        ListNode *current=head;

        for(length=0;current!=NULL;length++){
            current=(*current).next;
        }

        vector<int> chain(length);

        current=head;

        for(int j=0;j<length;j++){
            chain[length-1-j]=current->val;
            current=current->next;
        }

        return chain;
    }
};
```
### 解题思路
官方思路。
### 知识点
**"."与"->"的区别**
"."一般情况下读作"的”。
"->"一般读作"指向的结构体的"。
（引用博主faihuang的说法）
```
ListNode a;
//对于"."
a.val=1;
//对于"->"
ListNode *it=&a;
it->val=1;
```


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
    void deleteNode(ListNode* node) {
        //由于找不到node之前的节点。采用官方思路。
        node->val=node->next->val;
        node->next=node->next->next;

    }
};
```
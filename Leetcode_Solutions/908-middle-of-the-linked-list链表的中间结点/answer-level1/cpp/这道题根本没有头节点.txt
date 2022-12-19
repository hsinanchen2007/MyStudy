### 解题思路
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
    ListNode* middleNode(ListNode* head) {
        ListNode *zero =new ListNode(0);
        zero->next=head;
        ListNode *fl=zero;
        ListNode *ll=zero;
        while(fl->next&&fl->next->next)
        {
            fl = fl->next->next;
            ll = ll->next;
        }
        ll=ll->next;
        return ll;
    }
};
```
原来以为题目描述正确，直接快慢指针解题，结果怎么也不对，还以为自己理错了。
等到怎么改都不对，试了一下输入[1],结果他给我输出了个空指针，哈哈，原来是没有头节点，添加一个咯，完美解决
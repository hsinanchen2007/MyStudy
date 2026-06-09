### 解题思路
1-2-3-4-5
变1-3-5；2-4一个循环，奇偶分别链接
再5-2链接，合并
当为空时返回
当1个或者2个节点时候 不进入循环，直接返回
无论总节点数是奇数还是偶数，奇指针最终在最后一个节点停下，而偶指针停在最后一个节点，或者是空节点
所以while（偶节点为空或者下一个节点为空）
如1-2-3-4-5-null，l1停在5，l2停在null
1-2-3-4，          l1 在3，l2在4（下一个节点为null）

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* l1=head;
        ListNode* l2=head->next;
        ListNode* t=head->next;
        while(l2&&l2->next){
            l1->next=l2->next;
            l2->next=l1->next->next;

            l1=l1->next;移动到下一个奇偶节点
            l2=l2->next;
        }
        l1->next=t;
        return head;

    }
};
```
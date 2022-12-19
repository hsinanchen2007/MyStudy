### 解题思路
1.使用递归来完成两个有序链表的合并。
2.merge中当L1结点为空时则返回L2结点，若L2结点为空时返回L1结点。
3.merge中当L1结点的value比L2结点的value小则返会L1结点，反之当L2结点的value大于等于L1的结点则返回L2结点。
4.当L1结点或L2结点返回欠，修改返回结点的next指针，递归调用merge函数，函数传入较小结点的下一个结点，以及较大的结点。merge函数会返回一个两个结点中较小的一个结点。

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }
        else if(l2 == NULL){
            return l1;
        }
        else if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};
```
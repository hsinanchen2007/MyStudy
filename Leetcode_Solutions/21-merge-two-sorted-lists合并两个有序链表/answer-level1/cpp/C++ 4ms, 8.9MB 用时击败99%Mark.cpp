### 解题思路
链表处理，为了节约空间，将l2并入l1。

![image.png](https://pic.leetcode-cn.com/ae680f34660027ab26e4842fb562709c730de5ad8a25070c940fbfd0053abdf6-image.png)

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
        // 处理空链表
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        // 保证l1中的首结点为最终链表的头节点
        if(l1 -> val > l2 -> val) swap(l1, l2);
        // tmp 为临时结点，head 存放最终链表头节点
        ListNode* tmp = nullptr;
        ListNode* head = l1;
        while(l1 -> next != NULL && l2 != NULL)
        {
            // l1 中结点小于等于 l2
            while(l1 -> next != NULL && l1 -> next -> val <= l2 -> val)
            {
                l1 = l1 -> next;
            }
            if(l1 -> next == NULL) break;
            // l2 中结点小于 l1
            while(l2 != NULL && l1 -> next -> val > l2 -> val)
            {
                // l2 结点插入 l1
                tmp = l2;
                l2 = l2 -> next;
                tmp -> next = l1 -> next;
                l1 -> next = tmp;
            }
        }
        // 若 l1 非空，则自然接在链表尾端，若 l2 非空，则将当前头节点接在 l1 尾端
        if(l2 != NULL)
            l1 -> next = l2;
        return head;
    }
};
```
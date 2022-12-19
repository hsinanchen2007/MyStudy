### 解题思路
简单链表交换，理清结点交换前后关系即可。
需要注意，数据中存在空链表和长度为单数的链表。

![image.png](https://pic.leetcode-cn.com/959a21bad787aa91555d7b1c543936f1647594672fdde0d8587dce871a5e9bab-image.png)

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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head -> next == NULL) return head;
        // pt 存放原链表中前一节点，pr 存放原链表中后一节点，pl 存放原链表中前一节点的前一节点
        ListNode* pt = head;
        ListNode* pr = head -> next;
        ListNode* pl = NULL;
        // 交换第一对节点
        pt -> next = pr -> next;
        pr -> next = pt;
        // 注意链表头节点发生改变
        head = pr;
        while(pt -> next != NULL)
        {
            pl = pt;
            pt = pt -> next;
            // 判定链表长度是否为单数
            if(pt -> next == NULL) break;
            // 交换结点
            pr = pt -> next;
            pl -> next = pr;
            pt -> next = pr -> next;
            pr -> next = pt;
        }
        return head;
    }
};
```
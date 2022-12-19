```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
```
- step1: 如果传入链表为空，直接返回空值即可
- step2: 假设removeElements已经实现，则只需将头结点与删除元素后的链表相连即可
- step3: 判断头结点是否为要删除的元素，如果是返回head->next; 否则返回head；
```c++
class Solution {
public:
    ListNode* removeElements(ListNode *head, int val) {
        if (!head)
            return NULL;
        
        head->next = removeElements(head->next, val);
        
        if (head->val == val)
            return head->next;
        else
            return head;
    }
};
```

- step1: 定义虚拟头结点，使其为链表真实结点的前一个结点
- step2: 定义tmpNode指向虚拟头结点
- step3: 使用tmpNode遍历链表，如果下个结点为要删除的元素，则令其指向下下个元素
- step4: 返回preHead->next;
```c++
class Solution {
public:
    ListNode* removeElements(ListNode *head, int val) {
        ListNode *preHead = new ListNode(0);
        preHead->next = head;
        
        ListNode *tmpNode = preHead;
        while (tmpNode->next) {
            if (tmpNode->next->val == val)
                tmpNode->next = tmpNode->next->next;
            else
                tmpNode = tmpNode->next;
        }
        
        return preHead->next;
    }
};
```
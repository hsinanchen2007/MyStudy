两种方法：
1 使用一个指针遍历两次
第一次用于算出来倒数第N个节点是正数第几个节点
第二次用于删除节点
```
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
        ListNode* headhead = new ListNode(0);
        headhead->next = head;

        int len = 0;
        auto pt = head;
        while(pt)
        {
            len++;
            pt = pt->next;
        }
        int idx = len - n;
        pt = headhead;
        while(idx--)
        {
            pt = pt->next;
        }
        pt->next = pt->next->next;
        return headhead->next;
    }
};
```
2 使用两个指针，遍历一次
固定两个指针之间的距离，一旦前面一个指针到了尾部，那后面一个指针指向的就是要删除的
```
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
     auto dummy = new ListNode(0);
     dummy->next = head;
     auto left = dummy, right = dummy;
     int t = n + 1;
     while(t--)   
     {
         right = right->next;
     }
     while(right)
     {
         left = left->next;
         right = right->next;
     }
     left->next = left->next->next;
     return dummy->next;
    }
};
```

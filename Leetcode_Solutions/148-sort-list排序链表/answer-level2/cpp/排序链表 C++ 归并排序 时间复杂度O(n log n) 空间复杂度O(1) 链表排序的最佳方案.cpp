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

/**
 * 归并排序：先两个两个的merge，完成一趟后，再4个4个的merge，直到结束。其本质就是每次都合并两个有序链表，新链表是通过拼接给定的两个链表的所有节点组成的。所以可以做到空间复杂度为O(1)。归并排序实际上是对链表排序的最佳方案。
 */

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 经过排序好的链表头节点，头节点的next指向原链表的第一个节点。
        ListNode dummyHead(0);
        dummyHead.next = head;
        // 节点指针p，初始化指向原链表的第一个节点，计算链表长度length，最后p指向NULL
        ListNode *p = head;
        int length = 0;
        while (p) {
            ++length;
            p = p->next;
        }
        // size从1开始，每次循环左移1，size为每次循环的归并长度。
        for (int size = 1; size < length; size <<= 1) {
            // 当前节点，初始化指向原链表第一个节点元素
            ListNode *cur = dummyHead.next;
            // 尾巴节点，初始化指向经过排序好的链表头节点
            ListNode *tail = &dummyHead;
            while (cur) {
                ListNode *left = cur;
                ListNode *right = cut(left, size); // left->@->@ right->@->@->@...
                cur = cut(right, size);            // left->@->@ right->@->@  cur->@->...
                // 合并两个有序链表
                tail->next = merge(left, right);
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }
        /*
        * 举例：4->3->1->7->8->9->2->11->5->6->NULL
        * size=1: dh->(3->4)->(1->7)->(8->9)->(2->11)->(5->6)
        * size=2: dh->(1->3->4->7)->(2->8->9->11)->(5->6)
        * size=4: dh->(1->2->3->4->7->8->9->11)->(5->6)
        * size=8: dh->(1->2->3->4->5->6->7->8->9->11)
        */
        return dummyHead.next;
    }
    
    // 切断链表，将链表 head 切掉前 n 个节点，并返回后半部分的链表头。
    ListNode* cut(ListNode* head, int n) {
        ListNode* p = head;
        // p指向要切掉的第n个节点
        while (--n && p) {
            p = p->next;
        }
        // p指向的节点为空，返回空指针
        if (!p) return nullptr;
        // p指向的节点不为空，next指针指向p节点的下一个节点
        ListNode* next = p->next;
        // p节点的next置空
        p->next = nullptr;
        return next;
    }
    
    // 合并两个有序链表
    ListNode* merge(ListNode* l1, ListNode* l2) {
        // 头节点
        ListNode dummyHead(0);
        // p指针指向头节点，用以指针操作
        ListNode *p = &dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;       
            } 
            else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        // 当l1或l2有一个指向null了，把另一个的加进p链表里
        p->next = l1 ? l1 : l2;
        return dummyHead.next;
    }
};



#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummyHead(0);
    ListNode *p = &dummyHead;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            p->next = l1;
            p = l1;
            l1 = l1->next;
        }
        else {
            p->next = l2;
            p = l2;
            l2 = l2->next;
        }
    }
    p->next = l1 ? l1 : l2;
    return dummyHead.next;
}

ListNode* cut(ListNode* head, int n) {
    ListNode* p = head;
    while (--n && p) {
        p = p->next;
    }
    if (!p) return nullptr;
    ListNode* next = p->next;
    p->next = nullptr;
    return next;
}

ListNode* sortList(ListNode* head) {
    ListNode dummyHead(0);
    dummyHead.next = head;
    ListNode *p = head;
    int length = 0;
    while (p) {
        ++length;
        p = p->next;
    }
    for (int size = 1; size < length; size <<= 1) {
        ListNode *cur = dummyHead.next;
        ListNode *tail = &dummyHead;
        while (cur) {
            ListNode *left = cur;
            ListNode *right = cut(left, size);
            cur = cut(right, size);
            tail->next = merge(left, right);
            while (tail->next) {
                tail = tail->next;
            }
        }
    }
    return dummyHead.next;
}

int main() {
    ListNode node1(4); ListNode node2(2); ListNode node3(1); ListNode node4(3);
    ListNode *head = &node1; 
    node1.next = &node2; node2.next = &node3; node3.next = &node4;
    ListNode *res = sortList(head);
    while (res) {
        if (res->next) cout << res->val << "->";
        else cout << res->val;
        res = res->next;
    }
}


```
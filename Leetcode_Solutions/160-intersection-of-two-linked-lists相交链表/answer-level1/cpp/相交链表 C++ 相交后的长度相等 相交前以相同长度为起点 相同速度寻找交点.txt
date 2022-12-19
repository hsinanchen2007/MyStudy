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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        // 计算两个链表长度
        ListNode *pA = headA, *pB = headB;
        int lenA = 0, lenB = 0;
        while(pA->next) {
            ++lenA;
            pA = pA->next;
        }
        while(pB->next) {
            ++lenB;
            pB = pB->next;
        }
        // pA、pB从新指向两个链表头，长度较长的链表指针先向前跑差值，使得pA、pB的长度相等
        pA = headA, pB = headB;
        while(lenA > lenB) {
            pA = pA->next;
            --lenA;
        }
        while(lenB > lenA) {
            pB = pB->next;
            --lenB;
        }
        // 此时pA和pB同时向前跑，相遇即为相交节点
        while (pA != pB) {
			pA = pA->next;
			pB = pB->next;
		}
		return pA;
    }
};



#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;
    ListNode *pA = headA, *pB = headB;
    int lenA = 0, lenB = 0;
    while(pA->next) {
        ++lenA;
        pA = pA->next;
    }
    while(pB->next) {
        ++lenB;
        pB = pB->next;
    }
    pA = headA, pB = headB;
    while(lenA > lenB) {
        pA = pA->next;
        --lenA;
    }
    while(lenB > lenA) {
        pB = pB->next;
        --lenB;
    }
    while (pA != pB) {
        pA = pA->next;
		pB = pB->next;
	}
    return pA;
}

int main() {
    ListNode node1(4); ListNode node2(1); 
    ListNode node3(5); ListNode node4(0); ListNode node5(1);
    ListNode node6(8); ListNode node7(4); ListNode node8(5);
    ListNode *l1 = &node1; node1.next = &node2; node2.next = &node6;
    ListNode *l2 = &node3; node3.next = &node4; node4.next = &node5; node5.next = &node6;
    node6.next = &node7; node7.next = &node8;
    ListNode *res = getIntersectionNode(l1, l2);
    if (res) cout << res->val << endl;
    else cout << NULL << endl;
}


```
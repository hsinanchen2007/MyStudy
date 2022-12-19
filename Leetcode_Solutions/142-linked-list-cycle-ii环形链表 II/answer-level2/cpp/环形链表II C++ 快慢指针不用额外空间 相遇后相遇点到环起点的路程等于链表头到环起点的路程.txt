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
    // 快慢指针不用额外空间解题。不妨设表头为A，环起点为B，相遇点为C。注意到快指针路程必为慢指针两倍，慢指针路程为AB+BC，快指针路程为AB+BC+CB+BC==2（AB+BC）可知AB=CB，故快慢指针相遇后，可令一新慢指针由表头出发，两慢指针必相遇于环起点。另稍需注意 AB可能重合。
    ListNode *detectCycle(ListNode *head) {
        // 快慢指针都指向head
        ListNode* slow = head, * fast = head;
        do {
            // 如果某一个到NULL则说明无环
            if (slow == NULL || fast == NULL || fast -> next == NULL) {
                return NULL;
            }
            // 快指针向前2步
            fast = fast -> next -> next;
            // 慢指针向前1步
            slow = slow -> next;
        } while (fast != slow);
        // 当快慢指针相遇时退出循环，说明有环
        ListNode* node1 = head, * node2 = slow;
        // 从链表头和指针slow同时走，相等时则是环开始的位置
        while (node1 != node2) {
            node1 = node1 -> next;
            node2 = node2 -> next;
        }
        return node1;
    }
    
    /*
    // 取巧的O(n)算法。堆的地址从低到高，LeetCode的链表内存是顺序申请的，如果有环，head->next一定小于或等于head
    // 但是如果堆中的内存反复 new 和 delete , 后分配的地址不一定会比新分配的地址大，则这个思路就不成立了。
    ListNode *detectCycle(ListNode *head) {
        while(head) {
            if(!less<ListNode *>()(head, head->next)) {
                return head->next;
            }
            head = head->next;
        }
        return nullptr;
    }
    */
};




#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head, * fast = head;
    do {
        if (slow == NULL || fast == NULL || fast -> next == NULL) {
            return NULL;
        }
        fast = fast -> next -> next;
        slow = slow -> next;
    } while (fast != slow);
    ListNode* node1 = head, * node2 = slow;
    while (node1 != node2) {
        node1 = node1 -> next;
        node2 = node2 -> next;
    }
    return node1;
}

int main() {
    ListNode node1(3); ListNode node2(2); ListNode node3(0); ListNode node4(-4);
    ListNode *l1 = &node1; 
    node1.next = &node2; node2.next = &node3;
    node3.next = &node4; node4.next = &node2;
    ListNode *res = detectCycle(l1);
    if (res) {
        int pos = 0;
        while (res != l1) {
            l1 = l1->next;
            pos++;
        }
        cout << "pos = " << pos << endl;
    }
    else {
        cout << NULL << endl;
    }
}




```
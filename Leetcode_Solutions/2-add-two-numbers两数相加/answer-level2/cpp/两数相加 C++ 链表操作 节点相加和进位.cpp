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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 结果链表res，相加位数指针p，指向res
        ListNode res(0), *p = &res;
        // flag表示相加后进位数值
        int flag = 0;
        // 如果有l1或者有l2或者存在进位
        while (l1 || l2 || flag) {
            // 当前位求和
            int tmp = 0;
            if (l1 != nullptr) tmp += l1->val;
            if (l2 != nullptr) tmp += l2->val;
            tmp += flag;
            // flag十位取整，取整结果就是进位的数值
            flag = tmp / 10;
            // 求余，余值为结果res里要保存的每一位数字
            tmp %= 10;
            
            // next节点，先指向当前位l1，没有l1则指向l2
            ListNode *next = l1 ? l1 : l2;
            // 如果next节点为空，new一个新节点，给节点赋值为tmp，tmp是上一个节点进位而来的。
            if (next == nullptr) {
                next = new ListNode(tmp);
            }
            // next节点的值为当前位相加结果
            next->val = tmp;
            
            // 当前节点的next指针指向next节点
            p->next = next;
            // 当前节点指向next节点
            p = p->next;
            // l1、l2指向下一个节点，如果当前l1、l2为空，指向空
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        // res的第一个节点值是0，res的下一个节点才是计算结果的第一个数位。
        return res.next;
    }
};


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode res(0), *p = &res;
    int flag = 0;
    while (l1 || l2 || flag) {
        int tmp = 0;
        if (l1 != nullptr) tmp += l1->val;
        if (l2 != nullptr) tmp += l2->val;
        tmp += flag;
        flag = tmp / 10;
        tmp %= 10;
        ListNode *next = l1 ? l1 : l2;
        if (next == nullptr) {
            next = new ListNode(tmp);
        }
        next->val = tmp;
        p->next = next;
        p = p->next;
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }
    return res.next;
}

int main() {
    ListNode node1(2); ListNode node2(4); ListNode node3(3);
    ListNode *l1 = &node1; node1.next = &node2; node2.next = &node3; 
    ListNode node4(5); ListNode node5(6); ListNode node6(4);
    ListNode *l2 = &node4; node4.next = &node5; node5.next = &node6; 
    ListNode *res = addTwoNumbers(l1, l2);
    while (res) {
        cout << res->val;
        if (res = res->next) cout << "->";
    }
}



```
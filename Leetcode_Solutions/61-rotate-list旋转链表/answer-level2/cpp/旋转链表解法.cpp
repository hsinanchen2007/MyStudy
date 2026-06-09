## 1. 获取链表节点的数量
这里是递归获取链表节点的代码
```cpp
int getCount(ListNode* head) {
    return head ? (head->next ? 1 + getCount(head->next) : 1) : 0;
}
```
```cpp
int count = getCount(head);
```
## 2. 对k求模
计算k与节点数量的模，如果节点数量为0或者k与节点数量的模为0，则返回原链表。
```cpp
if (count == 0 || (k = k % count) == 0) return head;
```
## 3. 断开链表
把节点断开为前后两部分，前面那部分数量为(节点数量-k)，后面部分的节点数量为k. 获取前链表的尾部(front_tail), 则后链表的头部(back_head)为前链表尾部的下一节点.
```cpp
ListNode * front_tail = getElement(head, count - k - 1);
ListNode * back_head = front_tail->next;
```
根据索引获取链表节点的方式如下:
```cpp
ListNode* getElement(ListNode* head, int index) {
    return index ? getElement(head->next, index - 1) : head;
}
```
## 4. 调换链表位置
将前链表的尾部(front_tail)置空，后链表的尾部(back_tail)指向原来的头部(head)。
```cpp
front_tail->next = NULL;
ListNode * back_tail = getLast(back_head);
back_tail->next = head;
```
递归获取链表最后一个节点的方式如下:
```cpp
ListNode* getLast(ListNode* head) {
    return head ? (head->next ? getLast(head->next): head) : head;
}
```
完整的C++代码如下:
```cpp
#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    
    int getCount(ListNode* head) {
        return head ? (head->next ? 1 + getCount(head->next) : 1) : 0;
    }
    
    ListNode* getElement(ListNode* head, int index) {
        return index ? getElement(head->next, index - 1) : head;
    }
    
    ListNode* getLast(ListNode* head) {
        return head ? (head->next ? getLast(head->next): head) : head;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        int count = getCount(head);
        if (count == 0 || (k = k % count) == 0) return head;
        ListNode * front_tail = getElement(head, count - k - 1);
        ListNode * back_head = front_tail->next;
        front_tail->next = NULL;
        ListNode * back_tail = getLast(back_head);
        back_tail->next = head;
        return back_head;
    }
};
int main(int argc, const char * argv[]) {
    Solution solution;
    ListNode * node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(3);
    node->next->next->next = new ListNode(4);
    node->next->next->next->next = new ListNode(5);
    ListNode * node2 = solution.rotateRight(node, 2);
    cout << node2->val << endl;
    while (node2) {
        cout << node2->val <<  " ";
        node2 = node2->next;
    }
    cout << endl;
    return 0;
}

```
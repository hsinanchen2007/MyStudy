## 解题思路
此题的链表相交类似于两条河流相遇的场景，相遇后必定全部相交，相遇前必定分离

这里转换一个思路，不同长度的链表相交转换为相同长度链表相交的情况，具体步骤如下：
1. 先依次遍历A，B链表长度，得出size_a, size_b;
2. 再指针执行A，B链表的开始地址，记p_a, p_b；
3. 再将最长的链表从头移动 |size_a - size_b| 个节点长度，此时A ，B 链表剩余长度一样；
4. 再同时移动A， B链表的指针 p_a , p_b,当p_a = p_b 即相交的第一个节点；

空间复杂度O(1)
时间复杂度O(size_a + size_b + |size_a - size_b| + k) ,k>=0 ,最坏O(size_a + size_b + |size_a-size_b| + min(size_a,size_b)）,最好O(size_a + size_b ) ，所以为O(N).
## 代码实现
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
        if(headA==nullptr||headB==nullptr) return nullptr;
        int size_a = size(headA);
        int size_b = size(headB);
        ListNode *large = headA, * small =headB;
        int gap=size_a -size_b;
        if(gap<0){
            large = headB;
            small = headA;
            gap = 0-gap;
        }
        int i=0;
        while(i++<gap){
            large = large->next;
        }
        while(large!=nullptr){
            if(large == small) return large;
            large = large->next;
            small=small->next;
        }
        
        return nullptr;
    }

private:
    int size(ListNode * head){
        int length=0;
        ListNode *p = head;
        while(p!=nullptr){
            length++;
            p = p->next;
        }
        return length;
    }
};
```
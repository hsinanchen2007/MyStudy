## 声明：
1. 仅为个人想到的方案，若此思路上还有改进的余地，还望各位不吝赐教。
## 步骤：
1. 分别求出两个链表长度，记为$lenA$与$lenB$。
2. 反转其中一条链表(此处假设反转链表A），求出链表B长度记为$lenB\_$。
3. 则公共部分长度为$len\_common = (lenA + lenB - lenB\_ + 1) / 2$。
4. 为保证结构不变，再次反转A。
5. 判断假设的交点处是否真为交点。
## 原理：
1. 求相交长度：  
![微信图片_20190725102505.jpg](https://pic.leetcode-cn.com/d31fd4754d3d2b9ec745a754a2ac0dda0b6d2f59f08b31b865218a6f08d3c930-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20190725102505.jpg)
设公共部分长度为$len\_common$，链表A长度为$lenA$，链表B反转前长度为$lenB$，反转后长度为$lenB\_$，则显然:  
$$lenA + lenB = lenB\_ - 1 + 2 * len\_common \newline len\_common = (lenA + lenB - lenB\_ + 1) / 2$$
2. 注意事项：  
- 由于是假设相交，必须判断是否真的相交。
- 为了防止两条链表完全重合的情况，需要添加头结点以作判断。
## 不足：
1. `new`了两个头结点，但未`delete`。
## 复杂度分析：
1. 时间复杂度：３次长度统计，２次翻转，２次移动，约$O(n)$。
2. 空间复杂度：$O(1)$。
## 代码：
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        
        auto lenA = get_length(headA);
        auto lenB = get_length(headB);
        
        auto len_common = 0;
        if (lenA < lenB) {
            auto headA_ = reverse_list(headA);
            auto lenB_ = get_length(headB);
            reverse_list(headA_);
            len_common = (lenA + lenB - lenB_ + 1) / 2;
        }
        else {
            auto headB_ = reverse_list(headB);
            auto lenA_ = get_length(headA);
            reverse_list(headB_);
            len_common = (lenA + lenB - lenA_ + 1) / 2;
        }
        
        lenA -= len_common;
        lenB -= len_common;
        auto my_headA = new ListNode(0);
        my_headA->next = headA;
        for (auto i = 0; i < lenA; ++i)
            my_headA = my_headA->next;
        
        auto my_headB = new ListNode(0);
        my_headB->next = headB;
        for (auto i = 0; i < lenB; ++i)
            my_headB = my_headB->next;
        
        return my_headA->next == my_headB->next ? my_headA->next : nullptr;
    }
    
    int get_length(ListNode *head) {
        auto length = 0;
        while (head != nullptr) {
            length++;
            head = head->next;
        }
        return length;
    }
    
    ListNode* reverse_list(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        auto node = reverse_list(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
};
```
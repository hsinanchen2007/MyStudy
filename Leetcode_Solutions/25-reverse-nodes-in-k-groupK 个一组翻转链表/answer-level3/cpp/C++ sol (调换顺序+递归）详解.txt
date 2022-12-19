### 解题思路
执行用时 :8 ms, 在所有 C++ 提交中击败了98.95%的用户
内存消耗 :9.2 MB, 在所有 C++ 提交中击败了100.00%的用户

//

1. 看懂了 reverse 函数就看懂了一半，这里用 ListNode*& p, ListNode*& c 两个指针引用作为函数的返回值，其中p 代表的是已经调换好顺序且长度为k的子链表头，而c则是下一个调换循序的起始点：新的需要reverse的链表头。

```cpp
// 思考以下调换结构：
1->2->3->4->5->NULL
NULL<-2<-1<-4<-3<-5
```

2. 因此，我们利用reverseKGroup 主函数来做递归处理。当curr 有效时（说明还有可能潜在需要调换顺序的子链表：
   a) 首先判断一下从curr开始之后还剩多少个元素，按照题目要求如果剩余元素不足k个，那么保留其顺序不变。那么这样很好处理，我们仅需要将其append到prev的末尾即可。
   b) 如果a条件不满足，那么说明curr 后续的节点还需要进行顺序调整，递归调用reverseKGroup进行下一步动作。
3. 当递归结束时，返回prev，就是我们想要的结果。这里需要注意我们在递归前使用 tailPrev 来获得当前prev的链表末尾，这是为了让下一次递归结果能够顺利append到上一次结果上。这里需要注意一下。

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = nullptr;
        reverse(head, k, prev, curr);
        
        if (curr) {
            ListNode* tailPrev = prev;
            while (tailPrev && tailPrev->next) tailPrev = tailPrev->next;

            int leftCount = 0; ListNode* tmpCurr = curr;
            while (tmpCurr) { tmpCurr = tmpCurr->next; leftCount++; }

            tailPrev->next = leftCount >= k ? reverseKGroup(curr, k) : curr;
        }

        return prev;
    }

    void reverse(ListNode* head, int k, ListNode*& p, ListNode*& c) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr && k-- > 0) {
            ListNode* tmpNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmpNext;
        }
        
        p = prev;
        c = curr;
    }
};
```

观察你会发现，我们每次计算的 tailPrev 其实就是reserve 函数调用时传入的 head, 因此代码可以优化一下进一步提高效率：
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = nullptr;
        ListNode* prevTail = head;
        reverse(head, k, prev, curr);
        
        if (curr) {
            int leftCount = 0; ListNode* tmpCurr = curr;
            while (tmpCurr) { tmpCurr = tmpCurr->next; leftCount++; }

            prevTail->next = leftCount >= k ? reverseKGroup(curr, k) : curr;
        }

        return prev;
    }

    void reverse(ListNode* head, int k, ListNode*& p, ListNode*& c) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr && k-- > 0) {
            ListNode* tmpNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmpNext;
        }
        
        p = prev;
        c = curr;
    }
};
```
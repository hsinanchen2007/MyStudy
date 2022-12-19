### 解题思路
无论是递归还是非递归解法，其核心都在将整体的反转转化为pPre,pCur前后两个结点指向关系的更新。
只是对于非递归解法，需要实际上述两个指针以及pNext去保存不同时刻的结点，然后通过迭代更新指针内容。
而对于递归解法，则能利用递归栈的性质，由底向上(从后往前)地去保存结点，从而省掉了非递归中所需的开销(当然，递归依旧有不小的开销)

### 代码

**(一)非递归解法**
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||head->next==nullptr) return head;
        ListNode *pCur, *pPre;
        pCur=head;
        pPre=nullptr;
        while(pCur){
            auto pNext=pCur->next;
            pCur->next=pPre;
            pPre=pCur;
            pCur=pNext;
        }
        return pPre;

    }
};
```

**(二)递归解法**
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||head->next==nullptr) return head;
        ListNode *pNew=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return pNew;

    }
};
```
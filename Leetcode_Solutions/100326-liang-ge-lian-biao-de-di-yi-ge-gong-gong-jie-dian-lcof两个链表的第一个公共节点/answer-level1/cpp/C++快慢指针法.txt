### 解题思路
计算长-短=l 长的数组先走l然后一起走，比较是否指向同一个节点。
需要注意 这道题给的参数是头指针 不是数组

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
//法一：快慢法
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr||headB==nullptr) return nullptr;
        //if(headA==headB) return headA;
        //给的是头指针，先求链表长度
        int a=0,b=0;
        ListNode* A=headA;
        ListNode* B=headB;
        while(A!=nullptr) 
        {++a;A=A->next;}
        while(B!=nullptr)
        {++b;B=B->next;}
        
        int l=0;
        A=headA;
        B=headB;
        if(a<b)
        {
            l=b-a;
            for(int i=0;i<l;++i)
                B=B->next;
        }
        else if(b<a)
        {
            l=a-b;
            for(int i=0;i<l;++i)
                A=A->next;       
        }
        int k;
        if(a<b) k=a;
        else k=b;
        for(int i=0;i<k;++i)
        {
            if(A==B) return A;
            A=A->next;
            B=B->next;
        }
        //如果没有公共节点
        return nullptr;
  
    }
};
```
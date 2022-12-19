### 解题思路
思路一：暴力法
在第一链表上遍历时，每遍历到一个结点，把第二链表遍历一遍，如果第二链表上有一个结点和第一链表相同则返回次结点。
思路二：辅助栈
如果两个链表存在公共节点，那么从第一个公共节点起，后面的都是公共节点。因此公共节点只有一个next，不能分叉了。
所以如果能从最后一个公共节点往前，比较，最后一个相同的节点就是我们要找的。
但是单链表只能从头遍历到尾，现在需要先比较尾，因此想到利用辅助栈。
把两个链表的节点分别放入两个辅助栈。比较栈顶即可比较尾结点。
tip：
如何知道，当前栈顶元素是最后一组相同的节点呢？
方法是：
    设置A B来保存相同的节点，每次得到相同的节点，就赋值给A B，然后弹出。如果不相等，则只弹出，不赋值。
这样可以保证，即便是两个链表完全相同，也可以保留最后相同的头结点，而不会栈空了最后返回空值。
思路三：
先遍历两个链表，得到两个链表长度。
然后移动长的链表，使得移动后连个链表长度相同，这样在遍历时就可以一次遍历两个。
并且在判断相等时，比辅助栈方便。

### 思路二代码

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
        //特殊
        if(headB == NULL || headA == NULL)
            return NULL;
        //功能
        stack<ListNode*> s1;
        stack<ListNode*> s2;
        ListNode *A = headA; 
        ListNode *B = headB;    
        while(A != NULL)
        {
            s1.push(A);
            A = A->next;
        }
        while(B!= NULL)
        {
            s2.push(B);
            B = B->next;
        }
        while((!s1.empty()) &&(!s2.empty()))
        {
            
            if(s1.top() == s2.top())
            {
                A = s1.top();
                B = s2.top();
            }
            s1.pop();
            s2.pop();
            
        }
        return A;
    }
};
```
### 思路三代码

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
        //特殊
        if(headB == NULL || headA == NULL)
            return NULL;
        //功能
        ListNode *A = headA; 
        ListNode *B = headB;    
        int len1 = lenList(A);
        int len2 = lenList(B);
        if(len1 > len2)
        {
            int move = len1-len2;
            while(move--)
            {
                A = A->next;
            }
        }
        else if(len1 < len2)
        {
            int move = len2-len1;
            while(move--)
            {
                B = B->next;
            }
        }
        while(A != B && A !=NULL && B!=NULL)
        {
            A=A->next;
            B=B->next;
        }
        if(A==NULL)
            return NULL;
        else
            return A;
    }
    int  lenList(ListNode* head)
    {
        int res = 0;
        while(head != NULL)
        {
            ++res;
            head = head->next;
        }
        return res;
    }
};
```
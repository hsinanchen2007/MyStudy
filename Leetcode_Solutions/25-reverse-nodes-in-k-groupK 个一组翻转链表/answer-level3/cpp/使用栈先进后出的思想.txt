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
    ListNode* reverseKGroup(ListNode* head, int k) {

        std::stack<ListNode*> stack;
        ListNode* p,*Head;
        Head = new ListNode(0);
        p = Head;
        p->next = head;
        while(p->next!=NULL){
            ListNode *tem = p;
            
            for(int i=0;i<k;i++){
                p = p->next;
                if(p==NULL){
                    p = Head->next;
                    delete Head;
                    return p;
                }
                stack.push(p);
                // p=p->next;
            }
            p = p->next;
            for(int i=0;i<k;i++){
                tem->next = stack.top();
                stack.pop();
                tem = tem->next;
            }
            tem->next = p;
            p=tem;
            // p = tem;
        }
        p = Head->next;
        delete Head;
        return p;
    }
};
```
使用栈先进后出的思想,将链表的部分倒置,在这之前及之后保存这一段链表的上一个(`ListNode *tem = p;`)和下一个(`p = p->next;`),倒置结束后再接上
这一段代码无论使用什么语言实现都差不多
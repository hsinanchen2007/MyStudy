[原文](https://xduwq.blog.csdn.net/article/details/104902682)
# 栈
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
        //栈
        stack<ListNode*> sa,sb;//要把地址放进栈而不能把链表值放进栈
        ListNode* curA,*curB;
        curA = headA;
        curB = headB;
        while(curA!=nullptr){
            sa.push(curA);
            curA = curA->next;
        }        
        while(curB!=nullptr){
            sb.push(curB);
            curB = curB->next;
        }
        int n = 0;
        int size = sa.size();
        while(!sa.empty()&&!sb.empty()){
            if(sa.top()!=sb.top())
                break;
            else{
                sa.pop();
                sb.pop();
                n++;
            }
        }
        n = size-n;
        while(n--){
            headA = headA->next;
        }
        return headA;
    }
};
```
# 长链表先走
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
    int getLength(ListNode* head){
        int num = 0;
        while(head!=nullptr){
            num++;
            head =  head->next;
        }
        return num;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr||headB==nullptr)
            return NULL;
        ListNode* h1 = headA;
        ListNode* h2 = headB;
        int A = getLength(h1);
        int B = getLength(h2);
        bool flag = false;
        if(B>A){//判断哪个链表长
            int l = B-A;
            while(l--)
                headB = headB->next;//长链表先走
            while(headA!=nullptr&&headB!=nullptr){//现在两个链表一样长,同时移动
                if(headA==headB){
                    flag = true;
                    break;
                }
                headA = headA->next;
                headB = headB->next;
            }
        }else{
            int l = A-B;
            while(l--)
                headA = headA->next;
            while(headA!=nullptr&&headB!=nullptr){
                if(headA==headB){
                    flag = true;
                    break;
                }
                headA = headA->next;
                headB = headB->next;
            }
        }
        if(flag)
            return headA;
        return NULL;
    }
};
```
# 双指针
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
        ListNode* h1 = headA;
        ListNode* h2 = headB;
        while(h1!=h2){
            if(h1==nullptr)
                h1 = headB;
            else
                h1 = h1->next;
            if(h2==nullptr)
                h2 = headA;
            else
                h2 = h2->next;
        }
        //如果两个链表之间有交点的话,肯定会相遇;
        //如果两个链表之间没交点的话,相遇肯定是空指针,此处时也直接返回即可
        return h1;
    }
};
```



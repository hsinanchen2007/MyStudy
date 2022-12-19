## 解题思路
提供三种思路：递归法、栈法、三指针法
### 1、递归法
对于一个有n个节点的链表而言，对n个节点进行反转，就是把第1个节点接到第2-n个节点的反转结果的末尾。那么我们只需要用递归的手法进行整个链表反转即可。注意两点：当链表为空或者只有一个节点时，直接返回头指针head；反转过后的头指针head要对其next指针置空。
### 2、栈
这种方法的思路是最简单的，因为栈本身就是实现线性结构倒序的常用工具。因为是牺牲空间换取时间的做法，执行时间应该会比较短，但有较大空间消耗。这里申请一个存放节点的栈，将所有节点入栈，再按出栈顺序重构链表，最终的结果就是反转的结果。仍要注意在反转过后要将原head节点的next指针置空。
### 3、三指针法
这种方法只需要遍历一次链表，只需要三个指针的额外空间。和递归法一样，当链表为空或者只有一个节点时，直接返回头指针head。如果链表至少有两个节点时，我们三个指针node1、node2、node3分别指向head、head->next、head->next->next，这里node1和node2是要执行指向交换的节点，而node3是为了node1、node2的右移作准备。每次我们将指针方向由node1->node2改为node1<-node2，实现一对节点指向的反转。反转后，如果node3!=NULL，执行node2=node3,node1=node2，进行下一对节点指向的反转。和前两种方法一样，我们仍然要注意将原head的next指针置空。

## 代码

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
    //递归
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* subList = reverseList(head->next), *pos = subList;
        while(pos->next != NULL){
            pos = pos->next;
        }
        head->next = NULL;
        pos->next = head;
        return subList; 
    }

    //栈
    ListNode* reverseList(ListNode* head) {
        //节点入栈
        stack<ListNode*> myStack;
        while(head != NULL){
            myStack.push(head);
            head = head->next;
        }
        //重构
        ListNode* pos = new ListNode(0);
        head = pos;
        while(!myStack.empty()){
            pos->next = myStack.top();
            pos = pos->next;
            myStack.pop();
        }
        pos->next = NULL;
        return head->next;
    }

    //三指针
    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode *node1 = head, *node2 = head->next, *node3 = head->next->next;
        head->next = NULL;
        while(1){
            node2->next = node1;
            if(node3 == NULL){
                return node2;
            }else{
                node1 = node2;
                node2 = node3;
                node3 = node3->next;
            }
        }
        return NULL;
    }
};
```
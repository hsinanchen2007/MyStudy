**题目分析：**
1）第一次遍历求出链表中节点的个数；
2）第二次遍历找到第l-n个节点，修改节点的next指针，指向下下个节点，达到删除第n个节点的目的。

**具体代码：**
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //求解出链表中节点的个数l
        ListNode *p = head;
        int l = 0;
        while(p != NULL){
            l++;
            p = p->next;
        }
        
        //删除链表中第n个节点
        ListNode *dummy = new ListNode(NULL); //new 一个新的空节点，注意为NULL
        dummy->next = head; // 空节点指向head，让空节点和链表连起来
        p = dummy; //p指向空节点
        int m = l - n; 
        while(m > 0){
            p = p->next;
            m--;
        }
        p->next = p->next->next; //进行删除操作，该节点的next指向下下一个节点
        return dummy->next; //返回空节点的下一个节点，即头节点
    }
};
```
**tips：**
1）ListNode *dummy = new ListNode(NULL);
new的ListNOde一定要是空的；
2）return dummy->next;
return一定是空节点的下一个；
当测试样例只有一个节点时写“return head”会报错，
因为实际上return的应该是NULL，“return dummy->next;”符合要求。
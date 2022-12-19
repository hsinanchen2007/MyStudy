![image.png](https://pic.leetcode-cn.com/d296295320e575be216106ff834cde5f81f9a474fc6e1c1bde5721d6d796a26c-image.png)

我使用了一遍遍历完成删除。思路如下：
首先，让tmp1和tmp2相差n
然后，会出现两种情况，第一是n恰好为链表长度，第二是一般情况。
第一种情况，删除tmp1
第二种情况，tmp1和tmp2同时后移到tmp2为最后一个节点时，删除tmp1的next。
代码：
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
        ListNode *tmp1=head;
        ListNode *tmp2=head;
        ListNode *del;
        int tmp = n;
        while(tmp--){
            tmp2=tmp2->next;
        }
        if(tmp2==NULL){
            del = tmp1;
            tmp1=tmp1->next;
            delete del;
            return tmp1;
        }
        while(tmp2->next!=NULL){
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        del = tmp1->next;
        tmp1->next=del->next;
        delete del;
        return head;
    }
};
```

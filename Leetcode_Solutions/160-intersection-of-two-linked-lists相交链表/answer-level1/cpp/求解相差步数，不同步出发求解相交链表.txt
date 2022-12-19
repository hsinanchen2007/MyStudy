### 解题思路
该问题的关键是解决两个子链表如果有相交，那么他们在相交前的节点个数差是多少。我采用先连接后断开的方法计算。
首先将第一个子链表的尾节点连接到第二个子链表的头节点上。接下来从第二个子链表的头节点开始向后遍历，若不成环，则说明两个子链表
没有交点，在复原链表后返回空指针。若成环，计算环内节点数量。接下来从第一个子链表的头节点遍历，遍历到第二个子链表的头节点结束
计算节点数量，则二者相减，就是所要求的相差步数。接下来采用不同步出发，则可以得到所需节点，最后恢复链表，返回节点即可。

执行用时 :52 ms, 在所有 C++ 提交中击败了86.88%的用户
内存消耗 :16.2 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* end1=headA;
        if(headA==NULL||headB==NULL)
        return NULL;
        while(end1->next!=NULL)
        end1=end1->next;
        end1->next=headB;
        int count1,count2;
        count1=count2=0;
        ListNode* temp=headB;
        while(temp!=NULL){
        temp=temp->next;
        count1++;
        if(temp==headB)
        break;
        }
        if(temp==NULL){
        end1->next=NULL;
        return NULL;
        }
        temp=headA;
        while(temp!=NULL&&temp!=headB){
            temp=temp->next;
            count2++;
        }
        if(count1>count2){
            count1=count1-count2;
            temp=headB;
            for(int i =0;i<count1;i++)
            temp=temp->next;
            ListNode *temp2=headA;
            while(temp!=temp2){
                temp=temp->next;
                temp2=temp2->next;
            }
            end1->next=NULL;
            return temp;
        }
        else{
            count1=count2-count1;
            temp=headA;
            for(int i =0;i<count1;i++)
            temp=temp->next;
            ListNode *temp2=headB;
            while(temp!=temp2){
                temp=temp->next;
                temp2=temp2->next;
            }
            end1->next=NULL;
            return temp;
        }
        return NULL;
    }
};
```
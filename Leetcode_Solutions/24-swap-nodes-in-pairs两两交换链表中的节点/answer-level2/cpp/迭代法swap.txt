### 解题思路
此处撰写解题思路
迭代法：
1.创建一个哑节点dumpy；
2.循环内部，创建两个辅助节点firstNode和secondNode；
3.开始交换，让dumpy的next指向secondNode，firstNode的next指向secondNode的next，最后secondNode的next指向firstNode，连接起来；
4.交换完毕两个节点，开始下一对，所以dumpy变为firstNode，新的head变为firstNode的next；
5.当前节点为空或者只剩一个节点时，循环停止；
6.返回res头节点的next

对于链表的头节点与首元节点以及头指针尚未明确，因此描述不清...
另外，递归法真的好玄幻啊，理解不了啊....
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* res=new ListNode(0);
        res->next=head;
        ListNode* dumpy=res;
        while(head!=nullptr&&head->next!=nullptr){

        ListNode* firstNode=head;
        ListNode* secondNode=head->next;
        //swap
        dumpy->next=secondNode;
        firstNode->next=secondNode->next;
        secondNode->next=firstNode;

        dumpy=firstNode;
        head=firstNode->next;
    }
        return res->next;
    }
};
```
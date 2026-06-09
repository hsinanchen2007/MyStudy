### 解题思路
快慢双指针定位节点
### 代码

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //新建头指针,方便定位节点，操作，或者删除第一个节点
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        //first指针遍历获取长度
        int length=0;
        ListNode*first=head;
        while(first!=NULL){
            length++;
            first=first->next;
        }
        //找到需要删除的前一个节点
        length-=n;
        first=dummy;
        //从头指针开始，需要往后跳length 次
        while(length>0){
            length--;
            first=first->next;
        }
        first->next=first->next->next;
        return dummy->next;
    }
};




```
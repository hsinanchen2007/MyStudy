### 解题思路
一头扎进逻辑怪圈，差点没出来，是我太拉闸了
当前节点和下一个节点进行比较，如果相同，将当前节点和下个节点断链，和下下个节点连起来；如果不同，各自增一，继续下一轮比较。
后又发现一个指针就可以搞定了，难受，不干了。
### 代码

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==nullptr || head->next==nullptr)
            return head;
        ListNode *del = head;
        ListNode *copy = head;
        while (del->next != nullptr){
            if (copy->val == del->next->val) {
                del->next = del->next->next; //注意：不需要多此一举判断del->next->next==nullptr，因为下一轮的循环自然会判断。
                continue;           
            }
            copy = del = del->next;
        }        
        return head;
    }
};
```
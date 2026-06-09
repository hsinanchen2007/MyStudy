### 解题思路
设置一个odd节点以及even节点
分别指向最后一个奇数节点以及最后一个偶数节点。
只需把奇数位置上的节点连接到odd节点的后面即可，偶数节点就自然而然排列再后面

### 代码

```cpp

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return head;
        }
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *cur = head->next->next;
        int count = 3;
        while(cur != NULL){
            if(count % 2 != 0){
                ListNode *flag = cur->next;
                even->next = flag;
                even = flag;
                
                ListNode *temp = odd->next;
                odd->next = cur;
                cur->next = temp;
                odd = cur;
                
                cur = flag;
            }else{
                cur = cur->next;
            }
            count++;
        }
        return head;
    }
};
```
### 欢迎批评指正交流、共同进步！
### 解题思路
第一个参数是head，此时咱们判断下head-next是否存在，如果存在，则开始操作；否则，就不需要进行操作。
操作：交换head和head->next，这个交换和之前大家肯定做过的变量的交换相同，不多说。返回的是新的head。
交换完成后，对下一对结点进行同样的操作。需要注意一点：每对之间的连接不能断了，所以有这一行代码：
`head->next->next = swapPairs(head->next->next);`
### 代码

```cpp
class Solution {
public:
    static ListNode* swapPairs(ListNode* head) {
        if(head && head->next){
            ListNode* tmp = head->next;
            head->next = tmp->next;
            tmp->next = head;
            head = tmp;
            head->next->next = swapPairs(head->next->next);
        }
        return head;
    }
};
```
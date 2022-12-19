### 解题思路
思路日常参考 [@jyd](/u/jyd/) 大佬的题解。
倒数第$k$个节点，也就是第$n-k+1$个节点。
双指针的关键在于，设置相隔$k$步的两个指针，前指针在找到链表尾NULL时处于第$n+1$个节点，后指针位于$n+1-k$处。
另外就是考虑特殊情况，保证代码的鲁棒性:
1. head为空指针；
2. k大于链表的长度；
3. 输入的参数k为0；

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head == NULL || k==0)
            return NULL;
        ListNode* former = head;
        ListNode* later = head;
        for(int i = 0;i<k;i++)
        {
            if(former == NULL && i<k)
                return NULL;
            former = former->next;
        }
        while(former != NULL)
        {
            former = former->next;
            later = later->next;
        }
        return later;
    }
};
```
### 解题思路
  直接类比简单的求和运算，两位两位相加，若高位没有了则补零继续运算，直到所有节点都求和完毕，再看最高位还有无进位即可。

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);     //创建头节点
        ListNode* p = l3;   //链表指针

        int sum = 0,carry = 0;

        while(l1 != NULL || l2 != NULL){    //任一链表不为空都继续
            int x = (l1 != NULL) ? l1->val : 0;     //若有空链表，将获取的节点值设置为0
            int y = (l2 != NULL) ? l2->val : 0;
            sum = x + y + carry;    //求和
            carry = sum / 10;   //判断是否有进位

            p->next = new ListNode(sum%10);     //创建值节点
            p = p->next;    //移动链表指针

            if(l1 != NULL)  //移动l1l2
               l1 = l1->next;
            if(l2 != NULL)
               l2 = l2->next;
        }

        if(carry){  //l1和l2都遍历完了后还有进位的话
            p->next = new ListNode(carry);
            p = p->next;
        }

        return l3->next;
    }
};
```
### 解题思路
sum = carry + l1->val + l2->val;
carry = sum /10;

ListNode* tmp = (sum%10)
p(head)->tmp1->tmp2....

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
       
        ListNode *head = new ListNode(-1);
        ListNode *p = head;

		int sum = 0, carr = 0;
		
		//(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
		//输出：2 -> 1 -> 9，即912
		//两个链表直接从首节点开始加起
		
        while (l1 || l2 || carr) //如果改用&&则while结束还要多一些特判
        {
            sum = 0;//当前两位数字和
			
            if(l1 != NULL)//sum = 7
            {
                sum += (l1->val);
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                sum += (l2->val);
                l2 = l2->next;
            }
			
            sum += carr; //加上上一位的进位
			
            ListNode *tmp = new ListNode(sum % 10); //得到当前位数字
			
            carr = sum / 10; //得到当前位对下一位的进位
            p->next = tmp;   //当前位连接上去
            p = p->next;  //游标指针更新
        }
		
        return head->next;
    }
};
```
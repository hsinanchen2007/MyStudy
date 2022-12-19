思考一下发现手工求和步骤就是：
1. 先对应位求和（位数少的数对应位不存在就用0加）
2. 加上上一次的进位
3. 得到当前位
4. 记录进位

当**位数大的数遍历完（遍历完较长的链表）且进位也为0的时候**就可以停止了
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *head = new ListNode(-1), *p1 = l1, *p2 = l2, *p = head;//用带头节点的可以少一点初始的特判
        int sum = 0, carr = 0;
        while (p1 || p2 || carr) //如果改用&&则while结束还要多一些特判
        {
            sum = 0;//当前两位数字和
            if(p1)
            {
                sum += (p1->val);
                p1 = p1->next;
            }
            if(p2)
            {
                sum += (p2->val);
                p2 = p2->next;
            }
            sum += carr; //加上上一位的进位
            ListNode *t = new ListNode(sum % 10); //得到当前位数字
            carr = sum / 10; //得到当前位对下一位的进位
            p->next = t;//当前位连接上去
            p = p->next;//游标指针更新
        }
        return head->next;
    }
};

```

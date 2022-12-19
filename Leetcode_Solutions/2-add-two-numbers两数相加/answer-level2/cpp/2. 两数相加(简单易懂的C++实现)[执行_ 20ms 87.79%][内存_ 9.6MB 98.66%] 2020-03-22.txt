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

        //检查参数
        if(!(l1 && l2))
        {
            return NULL;
        }

        bool flag = false;//进位标记
        ListNode* pHead = NULL;//头结点, 返回值用
        ListNode* pItem = NULL;//当前计算节点
        int a = 0;//第一个值
        int b = 0;//第二个值

        while(l1 || l2)//避免位数不同不相加
        {
            if(l1)//不为空则取值, 否则取0
            {
                a = l1->val;
                l1 = l1->next;
            }
            else
            {
                a = 0;
            }

            if(l2)
            {
                b = l2->val;
                l2 = l2->next;
            }
            else
            {
                b = 0;
            }
           
           //添加节点
            if(!pHead)
            {
                pHead = pItem = new ListNode(a + b + flag);
            }
            else
            {
                pItem->next = new ListNode(a + b + flag);
                pItem = pItem->next;
            }

           if(pItem->val >= 10)//是否需要进位
           {
               pItem->val %= 10;
               flag = true;
           }
           else
           {
                flag = false;
           }

           
        }

        if(flag)//适用于 500 + 500 这种最后还需要进位的情况
        {
            pItem->next = new ListNode(1);
        }

        return pHead;
    }
};

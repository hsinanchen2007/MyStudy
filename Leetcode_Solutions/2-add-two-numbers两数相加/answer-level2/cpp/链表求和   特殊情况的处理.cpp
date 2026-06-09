### 解题思路
1.先求最长的链表长度，初始化求和链表
2.循环逐位计算求和，循环次数由最长的链表长度决定
3.逐位求和，只有两种情况，>=10，当前位贡献和对下一次循环位的贡献；分别定义两个delta即可。
4.细节考虑对于l1和l2不同长度时，需要对NULL节点补充新节点new ListNode(0)
对于l1和l2等长且进位情况，也需要对result->next== NULL补充新节点

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
        //先拷贝最长的链表，为返回链表的初始化
        int count1 = 0;int count2 =0;
        ListNode* l1_ = l1;
        ListNode* l2_ = l2;
        while(l1_)
        {
            count1++;
            l1_ = l1_->next;
        }
        while(l2_)
        {
            count2++;
            l2_ = l2_->next;
        }
        ListNode* result = count1 > count2 ? l1:l2;
        ListNode* backup = result;//记录求和链表的首指针，作为结果返回
        //逐个元素更新
        int deltaLast = 0;
        while(result != NULL)//循环计算次数由最长的链表长度决定
        {
            int l1Val = l1 == NULL? 0:l1->val;
            int l2Val  = l2 == NULL? 0:l2->val;
            int cur = l1Val + l2Val;
            result->val = cur + deltaLast >= 10 ? cur+deltaLast-10:cur+deltaLast;
            int deltaCur = cur + deltaLast >= 10? 1:0;
            if(deltaCur == 1 && result->next == NULL)
            {
                //为了防止l1和l2同长度，但求和进位了，需要为result补充长度
                result->next =  new ListNode(0);
                result = result->next;
            }
            else {result = result->next;}
            if(l1 != NULL || l2 != NULL)
            {
                //这里的l1和l2只要保证，能取next就取next，NULL就补充长度
                l1 = l1==NULL?new ListNode(0): l1->next;
                l2 = l2==NULL?new ListNode(0): l2->next;
            }
            deltaLast = deltaCur;
        }
        return backup;
    }
};
```
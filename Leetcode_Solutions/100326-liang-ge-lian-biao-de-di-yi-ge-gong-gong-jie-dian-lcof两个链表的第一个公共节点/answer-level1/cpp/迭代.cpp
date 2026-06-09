### 解题思路
先计算两个链表的长度，lenA和lenB，哪个长，哪个就先走|lenA-lenB|步，这样的话两个链表就到了同一个出发点，直接判断两个链表对应节点是否相等，相等的话即为公共节点。

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)return nullptr;
        int lenA = 0, lenB = 0;
        ListNode *temp = headA;
        while(temp)
        {
            ++lenA;
            temp = temp->next;
        }//得出链表A的长度
        temp = headB;
        while(temp)
        {
            ++lenB;
            temp = temp->next;
        }//得出链表B的长度
        //现比较2个链表的长度
        ListNode *tempA = headA, *tempB = headB;
        if(lenA > lenB)
        {
            //链表A比链表B长，链表A先走lenA-lenB步
            int steps = lenA - lenB;
            while(steps--)
            {
                tempA = tempA->next;
            }
            //现在链表A和链表B等长
            while(tempA && tempB)
            {
                if(tempA == tempB)
                    return tempA;
                tempA = tempA->next;
                tempB = tempB->next;
            }
        }
        else
        {
            //链表B比链表A长，链表B先走lenB-lenA步
            int steps = lenB - lenA;
            while(steps--)
            {
                tempB = tempB->next;
            }
            //现在链表B和链表A等长
            while(tempA && tempB)
            {
                if(tempA == tempB)
                    return tempB;
                tempA = tempA->next;
                tempB = tempB->next;
            }
        }
        return nullptr;  //运行到这都还没返回，说明没有公共节点
    }
};
```
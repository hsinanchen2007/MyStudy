按照平常的整数加法计算即可，则结果的第i位数字等于链表A的第i位的值加上链表B的第i位的值
再加上第i-1位的进位，即是结果的第i位，然后再求得本位的进位，将结果的节点
加入新链表即可。何时应该结束循环呢？容易想到，当两个链表都为空时，应该结束循环，其实
这是错误的，还应该再判断是否还有往下一位的进位，所以循环停止条件为，两链表都为空且无
向下一位的进位时结束循环。注意当一个链表的指针为空时，说明该链表已经遍历结束，但另一个
可能还为遍历结束，也就是一个指针为空，一个指针不为空，这时不能退出循环，还要继续做加法
运算，注意让指针为空的值为0即可，可能说的不是很清楚，但是下面代码应该是很清清楚了。


```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 记录进位
        int carry=0;
        // 记录该位的和 
        int sum=0;
        // 无用的头节点
        ListNode* newhead=new ListNode(0,nullptr);
        ListNode* nownode=newhead;
        // 当l1和l2都为空且无进位时才退出循环
        while(l1||l2||carry)
        {
            // 该结果位的值等于两链表对应位置的值之和再加上上一位的进位
            sum=(l1?l1->val:0)+(l2?l2->val:0)+carry;
            // 计算该位的进位
            carry=sum/10;
            // 该位的值等于sum与10取余
            ListNode* node=new ListNode(sum%10,nullptr);
            // 将新节点加入结果链表中
            nownode->next=node;
            nownode=nownode->next;

            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
        }
        
        return newhead->next;
    }
};
```

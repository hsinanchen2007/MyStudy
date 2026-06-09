### 解题思路
要点：dummyHead大法、断链、挂链、函数返回链表头和尾双参数。
![image.png](https://pic.leetcode-cn.com/1bd08556d78596939198b16a7fedbef6ab1322ea5ee3dbe0af9d13377a5c46df-image.png)

代码注释的很详细，简单易懂，如下。

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //特殊情况：NULL或仅有一个节点
        if(head == nullptr || head->next == nullptr)
            return head;

        //虚拟头结点
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        //next指向当前结点的下一个结点
        ListNode *next = head;
        //pre_tail指向上一段链表的尾节点，初始值为空指针
        ListNode *pre_tail = nullptr;
        //每一个段的头结点
        ListNode *newHead = head;
        //计数值，当count增加到k时，就断链，倒置，挂链
        int count = 0;

        while(head){
            count++;
            next = head->next;
            if(count == k){
                //断链，并且将该小段链表送入倒置函数中
                head->next = nullptr;
                HeadTail headTail = reverse(newHead);

                //挂链：处理倒置后的链表的头和尾，巧妙利用pre初始值是否为空
                if(pre_tail)
                    //不为空，则上一段链表尾节点指向新置链表头结点
                    pre_tail->next = headTail.head;
                else
                    //为空，则虚拟头结点指向新置链表头结点
                    dummyHead->next = headTail.head;

                headTail.tail->next = next;

                //更新上一段链表的尾节点、下一段链表的头结点和计数值count
                pre_tail = headTail.tail;
                newHead = next;
                count = 0;//别忘记计数值重置
            }
            
            head = next;
        }
        return dummyHead->next;//dummyHead大法好
    }

    //链表的头和尾结构体
    struct HeadTail{
        ListNode *head;
        ListNode *tail;
    };

    //reverse函数返回两个参数：倒置后的链表头和尾
    HeadTail reverse(ListNode* head){
        //巧妙使用pre指针，初始值为空
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next = head;
        while(cur){
            next = cur->next;
            //pre初始值为空
            cur->next = pre;
            //更新pre值，很巧妙
            pre = cur;
            cur = next;
        }
        HeadTail headTail;
        headTail.head = pre;
        headTail.tail = head;

        return headTail;
    }
};
```
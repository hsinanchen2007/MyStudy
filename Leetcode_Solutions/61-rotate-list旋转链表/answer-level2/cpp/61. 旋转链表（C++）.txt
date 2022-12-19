# 61. 旋转链表
**思路：**
题目中
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL

实质就是吧原链表分为两半部分:
1. 前半部分为：1->2->3；
2. 后半部分为：4->5

然后再把两部分重新进行连接。
而前后部分可有题目条件k推出。

# 所以可以遵循一下思路：

- 由于不知道链表长度，遍历一遍链表，获取链表长度，以及链表的尾指针；
- 然后将`（k % 链表长度）`取余获取真实步数；
- 再将`（链表长度-真实步数）`获取前半段长度；
- 重新重头部循环`（前半段长度-1）`找到结果链表尾结点：即找到：1->2->3；
- 最后将移动的后半段连接到前半段。（用到上面记录的尾指针）。
**完整代码：**
```
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
    ListNode* rotateRight(ListNode* head, int k) {
    	if( head == NULL )  return NULL;

        int step = 0;
        ListNode* temp = head;
        ListNode* rst  = NULL;
        ListNode* tail = NULL;

        while( temp != NULL ){
        	tail = temp;
        	temp = temp->next;
        	++step;
        }

        int r_step = k % step;
        if( r_step == 0 )  return head;
        r_step = step - r_step;

        temp = head;
        for( int i = 0; i < r_step-1; ++i ){
        	temp = temp->next;
        }
        rst = temp->next;
        temp->next = NULL;
        tail->next = head;

        return rst;
    }
};
```

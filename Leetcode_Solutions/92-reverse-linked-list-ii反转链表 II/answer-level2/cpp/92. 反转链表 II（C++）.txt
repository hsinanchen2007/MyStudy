# 92. 反转链表 II
**思路：**

- 首先需要定义一个头结点，并将其next指针指向head结点，头结点的作用是排除对一个节点操作时与其他结点的差别。因为不确定参数m是否为0。
```
        ListNode pre_head(0);
    	pre_head.next = head;
```

- 定义一些辅助的变量，由于需要把链表进行翻转，最容易想到的是使用头插法反转链表。但利用头插法时需要记录一些变量。
```
        ListNode* pre_reverse_begin = &pre_head;    //记录翻转之前的结点，将需要反转的结点都头查到该点之后
    	ListNode* reverse_begin = head; //记录翻转后的最后一个节点，也就是翻转前的第一个节点，用于翻转后链接成结果链表
    	ListNode* temp = NULL;  //临时变量
```

- 然后循环`m-1`次，找到找到翻转起始点的前一个结点。
```
        for( int i = 1; i < m;i++ ){
        	pre_reverse_begin = pre_reverse_begin->next;
        }
```

- 循环(m-n+1)头插到找到翻转起始点的前一个结点后。
```
        reverse_begin = pre_reverse_begin->next;
        head = reverse_begin;

        for( int i = m; i <= n; ++i ){
        	temp = head->next;
        	head->next = pre_reverse_begin->next;
        	pre_reverse_begin->next = head;
        	head = temp;
        }
```

- 连接得到结果链表。
```
          reverse_begin->next = head;
```

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	ListNode pre_head(0);
    	pre_head.next = head;

    	ListNode* pre_reverse_begin = &pre_head;
    	ListNode* reverse_begin = head;
    	ListNode* temp = NULL;

        //找到翻转起始点的前一个点
        for( int i = 1; i < m;i++ ){
        	pre_reverse_begin = pre_reverse_begin->next;
        }

        reverse_begin = pre_reverse_begin->next;
        head = reverse_begin;

        for( int i = m; i <= n; ++i ){
        	temp = head->next;
        	head->next = pre_reverse_begin->next;
        	pre_reverse_begin->next = head;
        	head = temp;
        }

        reverse_begin->next = head;

        return pre_head.next;
    }
};
```


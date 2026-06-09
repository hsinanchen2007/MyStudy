
我的思路是这样的 ，比较笨 ，但是容易理解：

1.首先快慢指针找到中点

    两个指针指head, 一个一次跳一个  另外的一次跳两个 ， 等到快指针跳不下去的时候，慢指针刚好在中点

    这里有两种情况 奇数个和偶数个
    1 2 3 4 5   快指针会落到3上 
    1 2 3 4     快指针会落到2上 （上中位数）
2.逆序后面的链表
	此时需要让慢指针的位置指向空 并来到慢指针的下一个 
	
	比如：
    1 2 3 4 5       3的位置指空， 然后来到4  从4开始逆序  返回以5为头的一个链表  得到 1->2->3->NULL  和  5->4->NULL
    1 2 3 4         2的位置指空， 然后来到3  从3逆序      返回以4为头的链表      得到 1->2->NULL    和  4->3->NULL


    
3. 然后双指针重连起来就行了



```
class Solution {
public:
	void reorderList(ListNode* head) {
        
        if( head == NULL || head->next == NULL || head->next->next == NULL)    //如果节点少于3个直接返回
        {
            return ;
        }
        
		ListNode * s = head;                               //定义快慢指针 
		ListNode * q = head;

		while (q->next != NULL && q->next->next != NULL)   //快指针的下一个空 或者快指针下下为空  都跳出 这样 慢指针落在中间
		{
			s = s->next;
			q = q->next->next;
		}
		
        ListNode * temp = s->next;                         //这三行为了断开两个链表 并且向下挪一位准备逆序
		s->next = NULL;
		s = temp;
		
        
        ListNode * tail = Reverse(s);                       //逆序 得到了以原链表 尾巴 为头的一个新链表

		s = head;                                           //复用了一下上面定义过的变量， 分别指向两个链表的头
		q = tail;

		while( s != NULL && q != NULL)
        {
            ListNode * sn = s->next;                        //链表1 把next保留住， 然后next指向另一个链表的 位置
            s->next = q;
            
            ListNode * qn = q->next;                        //链表2 同理
            q->next = sn;
            
            s = sn;                                         //然后两个指针都挪到下一位上
            q = qn;
        }
	}

	ListNode * Reverse(ListNode * head)                      //递归逆序链表  或者 双指针逆序链表
	{
		if (head->next == NULL)
		{
			return head;
		}

		ListNode * tail = Reverse(head->next);
		head->next->next = head;
		head->next = NULL;

		return tail;
	}
};


```

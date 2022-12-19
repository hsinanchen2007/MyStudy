### 解题思路
解题思路基本都注释在程序中了，采用快慢指针的方法，快指针每次比慢指针多走一格，如果快指针碰到了链表的末尾，则不是环形链表，如果快指针中的地址等于慢指针的地址，则为环形链表，显然在慢指针走完一圈之内，快指针能追上慢指针(可以理解为跑步中套圈的情况)。

有趣的是这里只需要满足快指针比慢指针速度快一格就行，也就是说可以同时增加快慢指针的速度就提高程序的运行速度，如果有兴趣可以再提高快慢指针的速度。（见程序2）

### 程序1

```cpp
class Solution {
public:
bool hasCycle(ListNode *head) {
		ListNode *fast = head;    //创建快指针
		ListNode *slow = head;    //创建慢指针
		while (fast&&fast->next)    //当所在链表及下一个不为空
		{
			fast = fast->next->next;   //快指针一次走两格
			slow = slow->next;         //慢指针一次走一格
			if (fast == slow)return true;    //指针的地址相同，则为回文链表
		}
		return false;   //否则不是
	}
};
```

### 程序2

```cpp
class Solution {
public:
bool hasCycle(ListNode *head) {
		ListNode *fast = head;    //创建快指针
		ListNode *slow = head;    //创建慢指针
		while (fast&&fast->next&&fast->next->next&&fast->next->next->next)    //当所在链表的n-1节不为空
		{
			fast = fast->next->next->next->next;    //快指针一次走n格
			slow = slow->next->next->next;          //慢指针一次走n-1格
			if (fast == slow)return true;    //指针的地址相同，则为回文链表
		}
		return false;   //否则不是
	}
};
```
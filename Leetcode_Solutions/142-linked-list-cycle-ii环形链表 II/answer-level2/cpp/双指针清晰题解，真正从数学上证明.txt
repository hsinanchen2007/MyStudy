很多题解没有讲清楚非环部分的长度与相遇点到环起点那部分环之间为何是相等的这个数学关系。这里我就补充下为何他们是相等的。
假设非环部分的长度是x，从环起点到相遇点的长度是y。环的长度是c。
现在走的慢的那个指针走过的长度肯定是`x+n1*c+y`，走的快的那个指针的速度是走的慢的那个指针速度的两倍。这意味着走的快的那个指针走的长度是`2(x+n1*c+y)`。

还有一个约束就是走的快的那个指针比走的慢的那个指针多走的路程一定是环长度的整数倍。根据上面那个式子可以知道`2(x+n1*c+y)-x+n1*c+y=x+n1*c+y=n2*c`。

所以有`x+y=(n2-n1)*c`,这意味着什么？我们解读下这个数学公式：非环部分的长度+环起点到相遇点之间的长度就是环的整数倍。这在数据结构上的意义是什么？现在我们知道两个指针都在离环起点距离是y的那个相遇点，而现在x+y是环长度的整数倍，这意味着他们从相遇点再走x距离就刚刚走了很多圈，这意味着他们如果从相遇点再走x就到了起点。
那怎么才能再走x步呢？答：让一个指针从头部开始走，另一个指针从相遇点走，等这两个指针相遇那就走了x步此时就是环的起点。


![image.png](https://pic.leetcode-cn.com/c8b9e51776903e4f6f8ad78d52161eb8d2cb98c2f5c010bcfb6c26c426d446bd-image.png)


```c++
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
    ListNode* detectCycle(ListNode* head) {
	ListNode* fastPtr=head, *slowPtr=head;
	// 让fast与slow指针第一次相遇
	while (fastPtr!=NULL && fastPtr->next!=NULL)
	{
		fastPtr = fastPtr->next->next;
		slowPtr = slowPtr->next;
		if (fastPtr==slowPtr)
		{
			// 从相遇点再走“非环部分长度”一定可以再次走到环起点
			fastPtr = head;
			while (fastPtr != slowPtr)
			{
				fastPtr = fastPtr->next;
				slowPtr = slowPtr->next;
			}
			return fastPtr;
			break;
		}
	}

	return nullptr;
}
};
```

### 解题思路
递归求解

对于自己写的递归，举例解释如下，以1-2-3-4-null为例
```
2->1->3->4->null
2->1->4->3->null
```

参照别人写的递归
```
2 1->3->4->null 
2 1->4  3->null
2 1->4->3->null
2->1->4->3->null

```
二者差异在于，我的是每次都会把head和next连接起来,而改进的是，在交换后再进行连接，因此需要保存的量少，变得也就更简洁了

### 代码

#### 自己写的递归

```cpp
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		//空节点或者只剩一个节点
		if (head == nullptr || head->next == nullptr) return head;
		else
		{
			//交换列表中的前两个节点head和head.next
			ListNode* tempFirst = head;
			ListNode* tempHead = head->next;//交换后新的头节点为head.next
			ListNode* tempSecond = head->next->next;
			head->next->next = tempFirst;
			head->next = tempSecond;
			head = tempHead;//更新一下交换后的头节点
			//将交换后子列表的返回头和head.next.next相连
			head->next->next = swapPairs(head->next->next);
		}
		return head;
	}
};
```
#### 参考别人写的递归

```cpp
//参考别人后更简化的写法
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		
		//空节点或者只剩一个节点
		if (head == nullptr || head->next == nullptr) return head;
		ListNode* next = head->next;
        //将子列表的返回节点与head.next相连，形成新的链表
		head->next = swapPairs(next->next);
		//将交换后的next指向head，将next和head连接起来
		next->next = head;
		return next;
	}
};
```
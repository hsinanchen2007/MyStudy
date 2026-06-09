### 解题思路
#### hashmap法
思路简单，时间复杂度O(n),空间复杂度O(n)

#### Floyd法
知道结论进行编程容易，但是自己推导出Floyd公式比较难，理解该方法，进行编程即可
时间复杂度O(n),空间复杂度O(1)

### 代码

#### hashmap法

```cpp
class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return nullptr;
		unordered_map<ListNode*, int> nodeMap;
		ListNode* cur = head;
		while (cur)
		{
			if (nodeMap.find(cur) != nodeMap.end()) return cur;
			nodeMap[cur]++;
			cur = cur->next;
		}
		return nullptr;
	}
};
```



#### Floyd法
```cpp
class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		//特判
		//排除空节点或单个节点不成环的情况
		if (head == nullptr || head->next == nullptr) return nullptr;
		ListNode* slow, * fast;
		slow = head;//slow和fast要从head同时出发，要不然根据Floyd的原理进行指针移动会发生死循环
		fast = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (fast==slow)//存在环
			{
				fast = head;//fast重置为head，slow不变，然后fast和slow现在开始每次只走一步，相遇点就是环的入口
				while (fast!=slow)
				{
					fast = fast->next;
					slow = slow->next;
				}
				return fast;
			}
		}
		return nullptr;
	}
};
```
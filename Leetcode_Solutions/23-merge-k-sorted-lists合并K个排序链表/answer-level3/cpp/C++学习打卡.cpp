### 解题思路
开始写了逐个比较，因为觉得跟分治归并时间复杂度差不多就先写了打算看看题解大神的解答，看了题解之后发现我错了，k和logk的差距还是很大的，当数组数较少时不明显，若数组多则时间消耗很明显。
还是自己的时间复杂度掌握不精

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
//逐个比较取最小值
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		bool delNullList = false;
		for (int i = 0; i < lists.size();i++) {
			delNullList = false;
			for (int j = 0; j < lists.size(); j++) {
				if (lists[j] == nullptr) {
					lists.erase(lists.begin() + j);
					delNullList = true;
					break;
				}
			}
			if (delNullList == false) {
				break;
			}	
		}
		if (lists.size() == 0) { return nullptr; }

		ListNode *head = new ListNode(0), *ans = head;
		while (lists.size() > 1) {
			int curMinIndex = 0;
			for (int i = 1; i < lists.size(); i++) {
				curMinIndex = (lists[curMinIndex]->val < lists[i]->val) ? curMinIndex : i;
			}
			head->next = lists[curMinIndex];
			lists[curMinIndex] = lists[curMinIndex]->next;
			head = head->next;
			if (lists[curMinIndex] == nullptr) {
				lists.erase(lists.begin() + curMinIndex);
			}
		}
		head->next = lists[0];
		lists.erase(lists.begin());
		head = ans;
		ans = ans->next;
		delete head;
		return ans;
	}
};


//分治，归并
class Solution {
private:
	ListNode* merge2Lists(ListNode* list_1, ListNode* list_2) {
		ListNode *newHead = new ListNode(0), *temp = newHead;
		while (list_1 != nullptr && list_2 != nullptr) {
			if (list_1->val < list_2->val) {
				newHead->next = list_1;
				list_1 = list_1->next;
				newHead = newHead->next;
			}
			else {
				newHead->next = list_2;
				list_2 = list_2->next;
				newHead = newHead->next;
			}
		}
		if (list_1 == nullptr) {
			newHead->next = list_2;
		}
		if (list_2 == nullptr) {
			newHead->next = list_1;
		}
		newHead = temp->next;
		delete temp;
		return newHead;
	}

public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		deque<ListNode*>nodes;
		for (auto cur : lists) {
			if (cur != nullptr) { nodes.push_back(cur); }
		}
		if (nodes.size() == 0) { return nullptr; }

		while (nodes.size() > 1) {
			int nodeCount = nodes.size();
			for (; nodeCount > 1; nodeCount = nodeCount - 2) {
				ListNode *node_1 = nullptr, *node_2 = nullptr;
				node_1 = nodes.front();
				nodes.pop_front();
				node_2 = nodes.front();
				nodes.pop_front();
				nodes.push_back(merge2Lists(node_1, node_2));
			}
		}
		ListNode *ans = nodes.front();
		nodes.pop_front();
		return ans;
	}
};
```
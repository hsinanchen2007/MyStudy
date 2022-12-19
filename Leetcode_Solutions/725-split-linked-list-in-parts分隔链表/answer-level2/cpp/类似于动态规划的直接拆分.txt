### 解题思路
题目要求尽可能地平均分割链表，因此不能简单地直接求平均值并分摊给剩余的小部分，不妨换个思路，设法每次让每次分割都是最终能够被满足的结果。

可以想见，如果链表长`len`恰好能被`parts`(k)整除，那么直接平均分配就能达到目的。如果产生了余数，那么必然有一组链表长要大于商`len / parts`。这时候我们不妨让当前待分割链表长为`seq = len / parts + 1`，这个状态一定能够满足全局要求。那么，下一个待分割的链表长`len`自然为`len - seq` ，并且`parts`必然每次操作后就减一。这样我们就可以做到让函数自身去检测当前应该划分多少个结点，而不必手动计算。

![split.png](https://pic.leetcode-cn.com/595f89a5e80e48d8f281b5f8b0212d0fdd417e35ffed9a3e6059fb119c96c483-split.png)

### 代码

```cpp
class Solution {
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		int len = 0;
		ListNode* p = root;
		while (p) {
			len++;
			p = p->next;
		} //计算链表长度
		vector<ListNode*> ans;
		int nowLen = len; //设置当前链表长
		for (int i = k; i >= 1; i--) {
			ans.push_back(split(p, i, nowLen)); //split函数直接返回已经分割好的链表
		}
		return ans;
	}

	ListNode* split(ListNode* &p, int k, int& len) {
		if (!p) return NULL;             // 没有可分割的节点，直接返回NULL
		ListNode* head = p, *tail = NULL;
		int upper = len / k;
		if (len % k != 0) {
			upper++;
		}                                //upper 为当前分割链表长度
		for (int i = 0; i < upper; i++) {//开始分割
			if (i + 1 == upper) {       //到达分割边界
				tail = p;
			}
			p = p->next;
		}
		tail->next = NULL;              //链表分割完毕

		len -= upper;                   //更新原表长
		return head;                    //返回新链表头
	}
};
```
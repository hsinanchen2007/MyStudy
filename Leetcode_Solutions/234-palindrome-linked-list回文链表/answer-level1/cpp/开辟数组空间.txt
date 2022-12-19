执行用时 :24 ms, 在所有 C++ 提交中击败71.37%的用户
内存消耗 :17.1 MB, 在所有 C++ 提交中击败了5.05%的用户

### 代码

```cpp
class Solution {
public:
	bool isPalindrome(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return true;
		ListNode* t = head;
		vector<int>a;
		while (t)
		{
			a.push_back(t->val);
			t = t->next;
		}
		for (int i = 0, j = a.size() - 1; i < j; i++, j--)
		{
			if (a[i] != a[j])
				return false;
		}
		return true;
	}
};
```
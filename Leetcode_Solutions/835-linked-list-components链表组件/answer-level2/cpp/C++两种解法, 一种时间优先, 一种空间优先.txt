```
class Solution {
public:
	// 暴力 - 时间换空间, 就原地判断
 	//Runtime: 288 ms, faster than 5.35% of C++ online submissions for Linked List Components.
	//Memory Usage : 12.7 MB, less than 89.47 % of C++ online submissions for Linked List Components.
	int numComponents(ListNode* head, vector<int>& G) {
		int res = 0;
		int len = 0;
		while (head != nullptr)
		{
			if (Contain(G, head->val))
			{
				len++;
			}
			else
			{
				if (len != 0)
				{
					res++;
					len = 0;
				}
			}

			head = head->next;
		}
		if (len > 0)
		{
			res++;
		}
		return res;
	}

	bool Contain(vector<int>& G, int value)
	{
		for (int i = 0; i < G.size(); ++i)
		{
			if (value == G[i])
			{
				return true;
			}
		}
		return false;
	}

	// 空间换时间 - 用额外的 unordered_set
	//Runtime: 28 ms, faster than 99.35% of C++ online submissions for Linked List Components.
	//Memory Usage : 14.7 MB, less than 26.32 % of C++ online submissions for Linked List Components.

	static const auto fast = []() {
		std::ios_base::sync_with_stdio(false);
		std::cin.tie(0);
		std::cout.tie(0);
		return 0;
	} ();

	int numComponents(ListNode* head, vector<int>& G) {
		int res = 0;
		unordered_set<int> temp(G.begin(), G.end());
		int len = 0;
		while (head != nullptr)
		{
			if (temp.count(head->val))
			{
				len++;
			}
			else
			{
				if (len != 0)
				{
					res++;
					len = 0;
				}
			}

			head = head->next;
		}
		if (len > 0)
		{
			res++;
		}
		return res;
	}
};
```

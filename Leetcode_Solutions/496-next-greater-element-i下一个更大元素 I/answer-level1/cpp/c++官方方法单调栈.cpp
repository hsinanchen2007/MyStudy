运行下来效率一般，甚至不如单独的对nums2建立一个map方便nums1查找，不过单调栈的思路很优秀。
```
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		int L1 = nums1.size();
		int L2 = nums2.size();
		stack<int> mystack = stack<int>();
		unordered_map <int, int> map = unordered_map<int, int>();
		vector<int> result = vector<int>(L1, -1);
		for (int i = 0; i < L2; ++i) {
			while (!mystack.empty()) {
				if (mystack.top() > nums2[i])break;
				map[mystack.top()] = nums2[i];
				mystack.pop();
			}
			mystack.push(nums2[i]);
		}
		while (!mystack.empty()) {
			map[mystack.top()] = -1;
			mystack.pop();
		}
		for (int i = 0; i < L1; ++i)
			result[i] = map[nums1[i]];
		return result;
	}
};
```

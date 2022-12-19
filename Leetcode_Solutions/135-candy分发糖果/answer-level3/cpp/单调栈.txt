### 解题思路
从左到右遍历，使用单调栈，如果当前的元素大于后面的元素，说明当前的元素需要修改，但是修改到何种程度，由两个方面组成，左边+右边。左边的影响很容易评估；主要是右边，所以可以将其“压栈”，往后遍历，一直到递减结束；那么该元素的前一个元素应该是2，然后3， 然后4。。。到了栈顶元素，取左右影响的最大值即可。

当然，这里实际上不需要用栈记录，只需要记录开始递减的value及其index即可。

### 代码

```cpp
class Solution {
public:
	void RefreshminValueFromStartIndex(vector<int>& ans, int minValue, int startIndex, int end)
	{
		int curV = 2;
		for (int i = end - 1; i >= startIndex; i--) {
			ans[i] = curV;
			curV++;
		}
		ans[startIndex] = max(ans[startIndex], minValue);
	}
	int GetCurrentItem(vector<int>& ratings, vector<int>& ans, int index)
	{
		if (index == 0) {
			return 1;
		}
		return ratings[index] > ratings[index-1] ? (ans[index-1] + 1) : ans[index];
	}
    int candy(vector<int>& ratings) {
        if (ratings.size() <= 1) {
			return ratings.size();
		}
		
		vector<int> ans(ratings.size(), 1);
		int startIndex = -1;
		int minValue = 0;
		for (int i = 0; i < ratings.size(); i++) {
			if (i == ratings.size() - 1) {
				if (startIndex != -1) {
					RefreshminValueFromStartIndex(ans, minValue, startIndex, i);
				} else {
					ans[i] = GetCurrentItem(ratings, ans, i);
				}
			} else {
				if (ratings[i] > ratings[i + 1]) {
					if (startIndex == -1) {
						startIndex = i;
						minValue = GetCurrentItem(ratings, ans, i);
					}
				} else {
					if (startIndex != -1) {
						RefreshminValueFromStartIndex(ans, minValue, startIndex, i);
						startIndex = -1;
						minValue = 0;
					}
					ans[i] = GetCurrentItem(ratings, ans, i);
				}
			}
		}
		int totalAns = 0;
		for (auto item : ans) {
			totalAns += item;
		}
		return totalAns;
    }
};
```
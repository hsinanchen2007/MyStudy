

### 代码

```cpp
class Solution {
public:
	int longestWPI(vector<int>& hours) {
		int pre_sum = 0, ans = 0;const int num = 10000;
		int index[num * 2];
		memset(index, -1, sizeof(index));
		for (int i = 0; i < hours.size(); i++) {
			pre_sum += hours[i] > 8 ? 1 : -1;
			if (pre_sum > 0)  ans = i + 1;
			else {
				if (index[pre_sum + num] == -1) index[pre_sum + num] = i;
				if (index[pre_sum - 1 + num] != -1) ans = max(ans, i - index[pre_sum - 1 + num]);
			}
		}
		return ans;
	}
};
```
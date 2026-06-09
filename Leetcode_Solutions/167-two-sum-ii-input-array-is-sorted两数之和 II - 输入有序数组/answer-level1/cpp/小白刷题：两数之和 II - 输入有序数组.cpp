有序数组想双指针，一头一尾，根据和值与target大小关系调整指针位置，直至相等

代码：
```
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int i = 0, j = numbers.size() - 1;
        vector<int> ans(2);
		while (i < j) {
			int sum = numbers[i] + numbers[j];
			if (sum == target) {
                ans[0] = i + 1;
                ans[1] = j + 1;
                break;
            }
			else if (sum < target)
				i++;
			else
				j--;
		}
        return ans;
	}
};
```

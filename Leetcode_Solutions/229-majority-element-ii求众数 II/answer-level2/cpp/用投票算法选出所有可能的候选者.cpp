### 解题思路

同169，只不过需要2个候选者。
因为要求时间复杂度为O(n)，所以不能排序；空间复杂度为O(1)，只能用常数个变量。
这样就限制了必须使用投票算法找出可能是众数的候选者，最多k-1个，所以就是2个候选者。
最后判断这两个候选者是不是满足要求，然后输出。

![image.png](https://pic.leetcode-cn.com/0af73be8bfbbcbec71efa8e5cf3a1a3091c4a3846213916055f7d1cdabeadb13-image.png)

### 代码

```cpp
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int candidate = -1,candidate2 = -1;
		int cnt = 0,cnt2 = 0;
		for (int num : nums){
			if (candidate == num){
				++cnt;
			}
			else if (candidate2 == num){
				++cnt2;
			}
			else{
				if (cnt == 0){
					candidate = num;
					cnt = 1;
				}
				else if (cnt2 == 0){
					candidate2 = num;
					cnt2 = 1;
				}
				else{
					--cnt;
					--cnt2;
				}
			}
		}
		cnt = 0,cnt2 = 0;
		//校验出现次数
		for (int num : nums){
			if (num == candidate){
				++cnt;
			}
			else if (num == candidate2){
				++cnt2;
			}
		}
		vector<int> result = {};
		if (cnt > nums.size() / 3){
			result.push_back(candidate);
		}
		if (cnt2 > nums.size() / 3){
			result.push_back(candidate2);
		}
		return result;
	}
};
```
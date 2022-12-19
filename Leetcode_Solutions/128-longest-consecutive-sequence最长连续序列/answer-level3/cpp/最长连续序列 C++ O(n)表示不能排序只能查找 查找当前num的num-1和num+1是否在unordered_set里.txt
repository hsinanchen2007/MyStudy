### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 将数组插入set
        unordered_set<int> s(nums.begin(), nums.end());
		int maxLen = 0;
		// 遍历nums中的每一个num
		for (int num:nums) {
            // 如果之前的数(num-1)在s中存在，则包含这个数字的序列已经被计算过，进入下次循环
			if (s.count(num - 1)) continue;
            // 如果之前的数(num-1)在s中不存在，则num是这个序列的第一个数字 
			else {
				int len = 1;
                // 如果之后的数(num+1)在s中存在，长度len加1，num加1，继续向后查找
				while (s.count(num+1)) {
					num++;
					len++;
				}
                // 更新maxLen的值
				maxLen = max(maxLen, len);
			}
		}
		return maxLen;
    }
};


#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int maxLen = 0;
    for (int num:nums) {
        if (s.count(num - 1)) continue;
		else {
            int len = 1;
			while (s.count(num+1)) {
                num++;
                len++;
            }
            maxLen = max(maxLen, len);
        }
    }
    return maxLen;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << endl;
}


```
### 解题思路
实在看不下去官方答案了，感觉还是自己的代码靠谱。
一个变量cover保存前面数组最大跳跃范围，判断cover是否包含当前下标，若不包含说明跳不到当前位置直接返回false；若能跳到当前位置，更新最大跳跃范围。

### 代码

```cpp
class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.empty() || nums.size() == 0) return false;
		int size = nums.size();
		int cover = 0;
		for (int i = 0; i<size; i++) {
			if (i>cover) return false;
			cover = max(cover, i + nums[i]);
		}
		return true;
	}
};
```
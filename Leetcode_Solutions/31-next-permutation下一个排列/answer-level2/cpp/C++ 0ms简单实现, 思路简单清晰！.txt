![image.png](https://pic.leetcode-cn.com/b81edb5f3d961f8990038b9fc02ad9eb9e9af74bb5c5bc2d9dab529e12e359a2-image.png)
执行0ms
### 解题思路
本题重要的是题目的理解与思路转换。
**思路：**
  从最末位寻找第一个破坏升序的数nums[pos - 1], 然后在遍历过的数里寻找比该数大的最小的一个数。
  如遍历过的数为[7,6,4,3], nums[pos - 1]为5, 则5需要与6进行交换, 在将[7,5,4,3]改为升序(这里使用reverse)。

  遍历过的数从后往前一定是升序, 故改为从前往后升序只需要反转该部分即可。
  寻找第一个比nums[pos - 1]大的数, 只需改为从前往后升序之后, 从升序的第一个数开始遍历比较大小即可。

### 代码

```cpp
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int pos = nums.size() - 1;
		while (pos > 0 && nums[pos] <= nums[pos - 1])
			pos--;
		reverse(nums.begin() + pos, nums.end());  //逆序
		if (pos > 0){
			int start = pos;
			for (; start < nums.size(); start++){ //寻找第一个大于nums[pos - 1]的数
				if (nums[start] > nums[pos - 1]){
					swap(nums[start], nums[pos - 1]); //交换
					break;
				}
			}
		}
	}
};
```
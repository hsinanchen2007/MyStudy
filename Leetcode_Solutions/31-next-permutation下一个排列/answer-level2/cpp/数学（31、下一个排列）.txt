### 解题思路
这道题像一道数学题。需要通过交换找到下一个更大的序列，首先需要明白，一个降序的序列肯定是不能存在下一个更大的序列的。
思路就是从最低位开始，找到一个数，将其变大，那么这个数肯定是比它大的里面的最小的（位数越低，数值越小）  因为某一个位做交换，要么变大，要么变小，交换之后变小了，不满足条件；所以发生交换的位越小越好。
那么怎么获取到满足条件的那个值呢？如果该位的更低位有比它大的数，那么找到里面最小的比它大的数，然后交换即可；

最开始想到搞完之后需要排个序，最后发现不用了；从后往前遍历，如果当前值小于前面的数，就直接做交换；也就是说遍历之后的数组是一个非递减的数组；
最后就是交换，遍历一次，选择后排序列里面比它大的数里面的最小的一个即可。

### 代码

```cpp
class Solution {
public:
	void ChangeArr(vector<int>& nums, int index, int maxNum)
	{
		int currentNum = nums[index];
		int ans = maxNum;
		int maxNumIndex = 0;
		for (int i = index; i < nums.size(); i++) {
			if (nums[i] > currentNum) {
				if (ans >= nums[i]) {
					maxNumIndex = i;
					ans = nums[i];
				}
			}
		}
		swap(nums[index], nums[maxNumIndex]);
		sort(nums.begin() + index + 1, nums.end());
	}
	
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        int maxNum = nums.back();
		int i = nums.size() - 1;
        for (; i >= 0; i--) {
            if (nums[i] < maxNum) {
				ChangeArr(nums, i, maxNum);
				return;
			}
			maxNum = nums[i];
        }
		sort(nums.begin(), nums.end());
    }
};
```
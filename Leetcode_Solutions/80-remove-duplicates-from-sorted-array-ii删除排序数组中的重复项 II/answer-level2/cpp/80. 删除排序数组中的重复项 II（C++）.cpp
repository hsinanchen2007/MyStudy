# 80. 删除排序数组中的重复项 II
**思路：**
遍历一遍传入数组，找到出现次数大于2次的相同数据，赋值为int型最大值；
遍历完成后，然后再排序一次原数组，返回新有效数组长度。
**代码实现：**
```
#define INT_MAX 0x7FFFFFFF
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int i = 0;
		int j = 1;
		int clean_sum = 0;
		while ( i+j < nums.size() ) {
			if ( nums[i] == nums[i+j] ){
				if ( j > 1 ) {
					++clean_sum;
					nums[i+j] = INT_MAX;
				}
				++j;
			} else {
				i = i + j;
				j = 1;
			}
		}
        sort(nums.begin(),nums.end());
		return nums.size() - clean_sum;
    }
};
```

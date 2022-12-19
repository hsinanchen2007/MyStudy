### 解题思路
解法一：与nums.back()比较
解法二：与nums[0]比较

### 代码

解法一
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return 0;
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int mid=l+r>>1;
            if(nums[mid]<=nums.back()) r=mid;
            else l=mid+1;
        }
        return nums[r];
    }
};
```
解法二

```cpp
class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.back() > nums[0]) return nums[0];
		int l = 0;
		int r = nums.size() - 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (nums[mid] < nums[0]) r = mid;
			else l = mid + 1;
		}
		return nums[r];
	}
};
```

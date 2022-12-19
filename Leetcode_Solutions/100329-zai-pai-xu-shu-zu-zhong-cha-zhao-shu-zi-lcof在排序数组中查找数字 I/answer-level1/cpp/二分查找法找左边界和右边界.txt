### 解题思路
由于第一位和最后一位都可能为target，所以初始化为-1与nums.size()

### 代码

```cpp
class Solution{
	public:
		int search(vector<int>& nums, int target){
			int end = nums.size();
			int start = -1;
			// 找左边界
			while(start+1 < end){
				int mid = start + (end-start) / 2;
				if(nums[mid] >= target){
					end = mid;
				}else{
					start = mid;
				}
			}
			// 找右边界
			int rstart = -1, rend = nums.size();
			while(rstart+1 < rend){
				int rmid = rstart + (rend - rstart) / 2;
				if(nums[rmid] <= target){
					rstart = rmid;
				}
				else{
					rend = rmid;
				}
			}
			return rend - start - 1;
		}
};

```
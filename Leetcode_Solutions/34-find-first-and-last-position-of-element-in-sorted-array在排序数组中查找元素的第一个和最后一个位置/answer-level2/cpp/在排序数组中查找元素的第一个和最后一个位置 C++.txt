首尾双指针+二分法
核心思路是先用二分法在mid位置找到target，然后再逐一移动首尾指针扩大范围；
注意，一定是left, right指向向内移动而不是向外移动，因为如果向外移动的话，上一轮的mid就是left,right的边界，上一轮就已经发现了；
vector<int> searchRange(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		vector<int> result;
		while (left <= right){
			int mid = (right - left) / 2 + left;
			if (nums[left] == target && nums[right] == target){
				result.push_back(left);
				result.push_back(right);
				return result;
			}
			if (nums[mid] < target) left = mid + 1;
			else if (target < nums[mid]) right = mid - 1;
			else{
				if (nums[left] == target) right -= 1;
				else if (nums[right] == target) left += 1;
				else{
					right -= 1;
					left += 1;
				}
			}
		}
		result.push_back(-1);
		result.push_back(-1);
		return result;
	}
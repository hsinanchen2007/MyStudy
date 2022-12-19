思路：
    有序数列旋转，log n，所以首先想到的就是通过二分查找做剪枝
    那么以中间值为中心，左右两边必然有一边是有序的，而另一边则是 一个子的有序数列
	所以二分查找就存在两种情况，即左侧有序、右侧旋转 或者 左侧旋转 右侧有序
	**我的思路就是 通过不断剪枝，将目标集合的size 减少的2个数字 以内，包括两个，直接比较即可**
    个人认为 二分搜索比较复杂的点 在于边界判断

```

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 一些临界条件判断
		if (nums.size() == 0) return -1;
		if (nums.size() == 1) return (nums[0] == target) -1;
		
        // 通过递归直接	进行二分查找
		return _binSearch(nums, target, 0, nums.size()-1);
	}
		
	int _binSearch(vector<int>& nums, int& target, int _left, int _right){
		// 如果left == right，说明通过剪枝，目标集合的size已经等于1了，直接判断即可
		if (_left == _right) return nums[_left] == target ? _left : -1;
		// 如果left>right，说明 通过剪枝，left 和 right的变化，集合size已经为空了
		if (_left > _right) return -1;
		// 这里增加判断size == 2 的情况，直接判断即可
        if (_left + 1 == _right) {
			if (nums[_left] == target) return _left;
			if (nums[_right] == target) return _right;
			return -1;
		}
        
		// 计算中间值的位置，并判断中间值是否等于target，直接返回
		int _mid = (_left + _right)/2;
		if (nums[_mid] == target) return _mid;
		
		if (nums[_mid] > nums[_left]){
			// 左侧有序， 右侧旋转（当然右侧也可能恰好有序，不过没有影响）
			if (nums[_left] <= target && target < nums[_mid]){
				//左侧有序，如果target 在左侧临界条件内，则进行剪枝，注意mid已不是target，所以，递归的时候是mid-1
				return _binSearch(nums, target, _left, _mid-1);
			}
			//如果没在左侧，那就有可能在右侧旋转序列里面，则剪枝左边，递归计算
			return _binSearch(nums, target, _mid+1, _right);
		}else{
			if (nums[_mid] < target && target <= nums[_right]){
				return _binSearch(nums, target, _mid+1, _right);
			}
			
			return _binSearch(nums, target, _left, _mid-1);
		}
	}

};

```

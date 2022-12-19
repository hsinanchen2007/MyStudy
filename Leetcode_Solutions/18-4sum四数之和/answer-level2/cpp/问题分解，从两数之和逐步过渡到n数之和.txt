问题分解,从两数之和开始：一个有序数组,两个指针分别指向头和尾。相等则加入结果集，小于头指针往后移，大于尾指针往前。每次相等后进行去重操作。

vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
	int end = nums.size() - 1;
    vector<vector<int>> result;
	while (start < end) {
		int lo = nums[start];
		int hi = nums[end];
        if (lo + hi == target) {
			result.push_back({ lo,hi });
        //去重
	        while (start < end &&   nums[start] == lo) {
				start++;
			}
			while (start < end && nums[end] == hi) {
				end--;
			}
        }else if (lo + hi > target) {
			end--;
		}
		else {
			start++;
		}
    }
	return result;
}

在两数之和的基础上，继续做三数之和。假设target为0，nums为{-1,0,-1,2},三数之和为0的条件可以转化为 一个数为-1的情况下,求两数之和为1(target(0)-(-1))的结果集，随后为每个结果集加入-1得到三数之和的结果集。同理，头指针移动后，转化为一个数为0/-1/2的情况，当头指针移动到倒数第三个数时,最后一种情况(0-1,2)也被遍历完了，所以当start<nums.size()-2时，遍历结束。
//为每个结果集加入一个数形成新的结果集
void  add(vector<vector<int>>& ori, int add_num) {
	
	for (int i = 0; i < ori.size(); i++) {
		ori[i].push_back(add_num);
	}
}
///三数之和
vector<vector<int>> threeSum(vector<int>& nums, int start,int target) {
	int end = nums.size() - 2;
	vector<vector<int>> result;
	while (start < end) {
		int lo = nums[start];
		vector<vector<int>> temp = twoSum(nums, start + 1, target - lo);
		add(temp, lo);
		result.insert(result.end(), temp.begin(), temp.end());
	
		while (start < end &&nums[start] == lo) {
			start++;
		}
	}
	return result;
}
同理，四数之和也可以转化为在知道一个数的条件下，求三数之和。

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());

	int end = nums.size() - 3;
	int start = 0;
	vector<vector<int>> result;
	while(start<end){
		int lo = nums[start];
		vector<vector<int>> temp = threeSum(nums, start + 1, target - lo);
		if (temp.size() > 0)
		{
			add(temp, lo);
			result.insert(result.end(), temp.begin(), temp.end());
		}
		while (start < end && nums[start] == lo) {
			start++;
		}
	}
	return result;
}
代码基本没变化，只是将求两数变成了求三数，以后n数之和也可以转化为求n-1数之和的问题。 


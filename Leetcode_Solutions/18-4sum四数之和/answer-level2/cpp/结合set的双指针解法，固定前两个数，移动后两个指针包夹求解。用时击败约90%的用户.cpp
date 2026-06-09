本解法利用set保存结果，避免重复元素的判断。

首先对数组进行默认升序排序，再使用四个指针(i<j<k<l)进行本题的求解。固定最小的i和j在左边，k=j+1,d=length-1，移动后面两个指针包夹求解。通过求解四元素之和与target的difference差值判断k和l的移动方向，difference大于0时l左移，小于0时k右移。当k>l时说明已经查找完j右边的所有元素，此时进入控制j的下一轮内循环，查找完后再回到外循环将i+1,重复上述查找。

执行用时：40ms，在所有cpp提交中击败88.93%的用户
内存消耗：9.5MB，在所有cpp提交中击败了72.78%的用户

```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int length = nums.size();
		sort(nums.begin(), nums.end());
		if (length < 4 || nums.front() > 0 || nums.back() < 0) return{};
		
		vector<vector<int>> res;
		set<vector<int>> ret;   //利用set的不重复值特性保存结果
        //分别用i,j,k,l对应四个元素
        //模仿三数之和，只不过这里前面是二重循环，即控制前两个元素
		for (int i = 0; i < length - 3; i++)
		{
			int first = nums[i];

			for (int j = i + 1; j < length - 2; j++)
			{
				int second = nums[j];
				int twoSum = first + second;
				int k = j + 1;
				int l = length - 1;

                //双指针法找到符合题意的后两个元素
                //这里不用判断重复值，因为是保存到set当中的，不存在重复元素
				while (l > k)
				{
					int difference = twoSum + nums[k] + nums[l] - target;
					if (difference == 0)
					{	
						ret.insert(vector<int> {nums[i], nums[j], nums[k], nums[l]});
						k++;
						l--;
					}
					else if (difference > 0)
					{
						l--;
					}
					else if (difference < 0)
					{
						k++;
					}
				}
			}
		}

        //将ret内的元素存入数组当中
		for (auto k : ret)
			res.push_back(k);
		return res;
    }
};
```

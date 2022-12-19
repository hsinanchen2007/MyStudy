根据题目要求,先用sort()函数对nums进行从小到大的排序.
若nums.size()小于三,那么返回倒数第一个数字就是最大的数字.
若nums.size()大于三,为了保证倒数第三个数是第三大的数,需要利用unique()函数进行去重,**注意判断去重后nums的大小!!!,本人就是第一次忘记了这个**,之后再根据去重后的大小返回倒数第一个数或者倒数第三个数.
代码如下:
```
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
		if (nums.size() < 3) 
			return nums[nums.size() - 1];
		else {
			nums.erase(unique(nums.begin(), nums.end()), nums.end());
			if(nums.size()<3)
				return nums[nums.size() - 1];
			else
				return nums[nums.size() - 3];
		}
    }
};
```
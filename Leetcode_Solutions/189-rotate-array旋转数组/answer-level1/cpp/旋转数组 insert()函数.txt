刚开始写的时候,因为不知道有insert()函数,不知道如何从头部插入元素,就先使用reverse()函数将nums翻转,每次在最后一位添加上nums[0],在使用erase()函数删除第一位,代码如下
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (!nums.empty() && k != 0 || k % nums.size() != 0) {
			int temp = k % nums.size();
			reverse(nums.begin(), nums.end());
			for (int i = 0; i < temp; i++){
				nums.push_back(nums[0]);
				nums.erase(nums.begin());
			}
			reverse(nums.begin(), nums.end());
		}
    }
};
```
但是显然这种方法会超时,在接触了insert()函数后,我直接从头部插入元素,那么问题便迎刃而解
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (!nums.empty() && k != 0 || k % nums.size() != 0) {
			int temp = k % nums.size();
			for (int i = 0; i < temp; i++){
				nums.insert(nums.begin(),nums[nums.size()-1]);
				nums.pop_back();
			}
		}
    }
};
```
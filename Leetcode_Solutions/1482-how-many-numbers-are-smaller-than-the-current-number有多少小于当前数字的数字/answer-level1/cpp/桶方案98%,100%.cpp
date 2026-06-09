#### 因为存储的数字范围是0-100，所以用一个101规模的数组，数组的索引对应各元素，各索引存放的内容对应其属性。
```
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        std::size_t size = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end()); // 排序，每个元素的索引，如果没有重复元素的话，即为小于该元素的数字个数

        for (int i = 0; i < 101; i++) {
            num[i] = -1; // 初始化桶
        }

        for (int i = 0; i < size; ++i) {
        	if (num[temp[i]] == (-1)) // 如果该元素未被更新，则更新其属性值
        		num[temp[i]] = i;
        }
        vector<int> ret;
        for (int i = 0; i < size; ++i) {
        	ret.push_back(num[nums[i]]);
        }
        return ret;
    }

private:
	int num[101];
};
```
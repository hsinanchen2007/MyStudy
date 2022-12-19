### 解题思路
和三指针的思路类似。
问题求的是任意位置的解，所以可以先对其进行排序。
排完序之后，从第一个数开始循环；第二、三指针从后一个、两个数开始循环，第四个数从最后开始循环；
这样，如果4个数之和大于target，只有将后面的前移；
      如果和小于target，显然将前面的往后移动，这样能够保证所有的数都被访问到了。
PS：如何去重，set即可。能让代码简单，不出错，是最关键的。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() <= 3) {
            return vector<vector<int>>();
        }
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        for (int i = 0; i < nums.size() - 3; i++) {
            for (int j = i + 1; j < nums.size() - 2; j++) {
                int leftIndex = j + 1;
                int rightIndex = nums.size() - 1;
                while(leftIndex < rightIndex) {
                    int currentCount = nums[i] + nums[j] + nums[leftIndex] + nums[rightIndex];
                    if (currentCount == target) {
                        ans.insert(vector<int> {nums[i],nums[j],nums[leftIndex],nums[rightIndex]});
                        leftIndex++;
                        continue;
                    }
                    if (currentCount < target) {
                        leftIndex++;
                    }
                    if (currentCount > target) {
                        rightIndex--;
                    }
                }
            }
        }
        vector<vector<int>> res;
        for (auto item : ans) {
            res.emplace_back(item);
        }
        return res;
    }
};
```
### 解题思路
该题关键在于如何去重。一开始偷懒用了set来去重，结果效率很低。
第二次想着，其实在j不断交换找到的不同数的时候，p后的数组其实一直是保持有序的，只要在运算前先保持数组，返回前重置数组，则可以保证在所有递归调用中都是有序的，但是内存消耗还是有点高。
第三次又分析了下一个一轮交换完成后，其实p位存着最大的数，只要取出p的数，放到nums末尾，则已经保证返回前已经重新使数组p之后保持有序
### 代码
最后方案
```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> sln;
        if (nums.empty()) return sln;
        sort(nums.begin(), nums.end()); // 后续关键操作时保持有序
        permute(sln, nums, 0);
        return sln;
    }
    void permute(vector<vector<int>> &sln, vector<int>& nums, int p) {
        // 注意，后续不管什么操作，p前的元素都是保持不动的
        int len = nums.size();
        if (p == len - 1) {
            sln.push_back(nums);
            return;
        }
        permute(sln, nums, p + 1);
        for (int i = p + 1; i < len; i++) {
            if (nums[p] != nums[i]) {
                int tmp = nums[p];
                nums[p] = nums[i];
                nums[i] = tmp;
                permute(sln, nums, p + 1);
            }
        }
        // 其实此时一定时最大的在前，后面都有序，只需把首位移到末尾即可恢复有序
        int tmp = nums[p];
        nums.erase(nums.begin() + p);
        nums.push_back(tmp);
        return;
    }
};
```
偷懒用个集合。用跟p相等或者i - 1相等来判断会乱。
```
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> sln;
        if (nums.empty()) return sln;
        permute(sln, nums, 0);
        return sln;
    }
    void permute(vector<vector<int>> &sln, vector<int>& nums, int p) {
        int len = nums.size();
        if (p == len - 1) {
            sln.push_back(nums);
            return;
        }
        permute(sln, nums, p + 1);
        set<int> s;
        s.insert(nums[p]);
        for (int i = p + 1; i < len; i++) {
            if (s.count(nums[i]) == 0) {
                s.insert(nums[i]);
                int tmp = nums[p];
                nums[p] = nums[i];
                nums[i] = tmp;
                permute(sln, nums, p + 1);
                tmp = nums[p];
                nums[p] = nums[i];
                nums[i] = tmp;
            }
        }
        return;
    }
};
```
### 2
优化，保持有序，但是需保存初始状态，返回前把数组重置为初始状态
```
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> sln;
        if (nums.empty()) return sln;
        sort(nums.begin(), nums.end()); // 后续关键操作时保持有序
        permute(sln, nums, 0);
        return sln;
    }
    void permute(vector<vector<int>> &sln, vector<int>& nums, int p) {
        int len = nums.size();
        if (p == len - 1) {
            sln.push_back(nums);
            return;
        }
        vector<int> tmpV(nums);
        permute(sln, nums, p + 1);
        for (int i = p + 1; i < len; i++) {
            if (nums[p] != nums[i]) {
                int tmp = nums[p];
                nums[p] = nums[i];
                nums[i] = tmp;
                permute(sln, nums, p + 1);
            }
        }
        nums = tmpV; // 返回前需复位
        return;
    }
};
```
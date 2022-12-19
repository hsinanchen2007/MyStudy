### 解题思路
此处撰写解题思路

### 代码

```cpp
/*
给定一个包含 m 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在 n 个元素，使得这 n 个元素相加的值与 target 相等？找出所有满足条件且不重复的组。
注意：
答案中不可以包含重复的组。

示例：
给定数组 nums = [1, 0, -1, 0, -2, 2]， target = 0，n = 4

满足要求的四元组集合为：
[ [-1, 0, 0, 1],
[-2, -1, 1, 2],
[-2, 0, 0, 2] ]
*/

class Solution {
public:
    // 统计其中的1的个数
    int NumOf1(int num) {
        int count = 0;  
        while (num) {  
            num = num & (num - 1);  
            count++;
        }
        return count;  
    }

    // 从长度为n的数组nums里选出m个数使和为target
    vector<vector<int>> calSum(vector<int> &nums, int target, int m) {
        vector<vector<int>> res;
        int n = nums.size();
        int bit = 1 << n;
        // 从1循环到2^n
        for (int i = 1; i < bit; i++) { 
            int sum = 0;
            vector<int> tmp;
            // 如果1的个数等于要选出来的m个数
            if (NumOf1(i) == m) {
                // 遍历这个数组，把标记为1的都找出来
                for (int j = 0; j < n; j++) {
                    // 用i与2^j进行位与运算，若结果不为0，则表示第j位不为0，从数组中取出第j个数
                    if ((i & 1 << j) != 0) {  
                        sum += nums[j];  
                        tmp.push_back(nums[j]);  
                    }  
                }  
                if (sum == target) {
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }

    vector<vector<int>> fourSum1(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res = calSum(nums, target, 4);
        sort(res.begin(),res.end(),[](vector<int> &a,vector<int> &b) {
            return a[0]<b[0] || (a[0]==b[0]&&a[1]<b[1]) || (a[0]==b[0]&&a[1]==b[1]&&a[2]<b[2]) || (a[0]==b[0]&&a[1]==b[1]&&a[2]==b[2]&&a[3]<a[3]);
        });
        res.erase(unique(res.begin(),res.end()), res.end());
        return res;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size()<4) return result;

        int n_size = nums.size();
        sort(nums.begin(), nums.end());
        // 第一个数从下标0开始遍历，遍历完倒数第四个数就可以结束
        for (int i=0; i<n_size-3; i++) {
            // 剪枝，因为后面取出来的是4个正数，和大于0
            if (target<=0 && nums[i]>0) break;
            // 剪枝，当前连续四个数和大于target，继续遍历的也都大于target
            if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            // 此时条件不满足，本轮循环没有满足的，可以结束
            if (nums[i]+nums[n_size-3]+nums[n_size-2]+nums[n_size-1]<target) continue;
            // 重复项
            if (i>0 && nums[i]==nums[i-1]) continue;
            // 第二个数从i+1开始遍历，此时降维到三数和
            for (int j=i+1; j<n_size-2; j++) {
                // 剪枝
                if (nums[j]+nums[j+1]+nums[j+2]>target-nums[i]) break;
                // 此时条件不满足，本轮循环没有满足的，可以结束
                if (nums[j]+nums[n_size-2]+nums[n_size-1]<target-nums[i]) continue;
                // 重复项
                if (j>i+1 && nums[j]==nums[j-1]) continue;
                // 双指针
                int start=j+1, end=n_size-1;
                while (start<end) {
                    int sum = nums[i]+nums[j]+nums[start]+nums[end];
                    if (sum<target) start++;
                    else if (sum>target) end--;
                    else {
                        // 在result末尾添加元素
                        result.push_back({nums[i], nums[j], nums[start], nums[end]});
                        // 移动l、r，准备查找下一组合适的l、r
                        start++, end--;
                        // 剔除重复项找合适的l、r
                        while(start<end && nums[start] == nums[start-1]) start++;
                        while(start<end && nums[end] == nums[end+1]) end--;
                    }
                }
            }
        }
        return result;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int target;
        vector<vector<int>> res;
        // 对给定区间所有元素排序，第三个参数没有则默认升序。
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // 去重，排序后，nums中的当前数字和上一个数字相同的话，进入下一个循环
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            // nums当前元素如果大于0，结束循环，不结束循环的话找到的也是重复的。
            if ((target = nums[i]) > 0) break;
            // l为nums数组当前元素的下一个元素下标，r为nums数组的最后一个元素下标
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] + target < 0) ++l;
                else if (nums[l] + nums[r] + target > 0) --r;
                else {
                    // 在res末尾添加元素
                    res.push_back({target, nums[l], nums[r]});
                    // 移动l、r，准备查找下一组合适的l、r
                    ++l, --r;
                    // 如果下标l、r的元素是前一个等于后一个，继续移动下标
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                }
            }
        }
        return res; 
    }

};
```
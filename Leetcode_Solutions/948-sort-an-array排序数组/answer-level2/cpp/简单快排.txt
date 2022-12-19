### 解题思路
通过简单地快速排序解决问题，pivot为最后一个元素

### 代码

```cpp
/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 *
 * https://leetcode-cn.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (58.90%)
 * Likes:    89
 * Dislikes: 0
 * Total Accepted:    41.5K
 * Total Submissions: 70.4K
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 * 
 * 
 */

// @lc code=start
class Solution {
    //本体就是一个排序算法，可以通过各种排序方式来解决
public:
    vector<int> sortArray(vector<int>& nums) {
        
        quickSort(0,nums.size()-1,nums);
        return nums;
    }

    void quickSort(int begin,int end,vector<int>& nums){

        if (begin<end)
        {
            int mid = partition(begin,end,nums);
            quickSort(begin,mid-1,nums);
            quickSort(mid+1,end,nums);
        }

    }
    int partition(int begin,int end,vector<int>& nums){
        //选择pivot
        int pivot = nums[end];
        int i = begin-1;
        for (int j = begin; j < end; j++)
        {
            if (nums[j]<=pivot)
            {
                i++;
                swap(nums[j],nums[i]);
            }
        }
        swap(nums[i+1],nums[end]);
        return i+1;
    }

};
// @lc code=end


```
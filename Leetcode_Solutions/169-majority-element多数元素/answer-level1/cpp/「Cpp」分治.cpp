### 解题思路

以[3,2,3]为例

low = 0, high =2, mid = 1, 
- [3,2] 和 [3]
- [3,2] => low = 0, high = 1, mid =1,分为两个元素 
  - [3] 返回 left=3
  - [2] 返回 right=2
  - left != right
  - 统计left和right，比较谁比较多，其实一样多，返回了2
- [3] 直接返回3

[2],[3]不相同，都一样多，返回3

代码最有趣多部分在于，在左半部分【3，2】中，返回的是2，然后【2】又和【3】比，明明2和3次树一样多，但是这次返回多是3，从而保证了最终都是3。

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int high = nums.size();
        int res = DC(nums, 0, high-1);
        return res;

    }
    int DC(vector<int>&nums, int low, int high){
        //只有一个元素
        if ( low == high) return nums[low];

        //分割元素, 递归
        int mid  = low + ((high-low) >> 1);
        int left = DC(nums, low,  mid);
        int right= DC(nums, mid+1, high);
        
        //如果左右一致，则合并
        if (left == right) return left;
        //如果不一致, 统计次数
        int leftCount = countNums(left, nums, low, mid);
        int rightCount = countNums(right, nums, mid+1, high);

        return leftCount >  rightCount ? left : right;

    }
    int countNums(int num, vector<int>& nums, int low, int high){
        int count = 0;
        for (int i = low; i <= high; i++){
            if (nums[i] == num) count+=1;
        }
        return count;
    }
};
```
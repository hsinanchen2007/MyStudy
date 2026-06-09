### 解题思路
通过hash表

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        map<int, int> a;    // 建立一个hash表
        vector<int> res(2, -1);     // 存放最终结果

        for(int i = 0; i < len; ++i){
            // 遍历一遍nums，把遍历到的元素加到hash表中，nums[i]为键，索引为值
            if(a.count(target - nums[i]) > 0 && a[target - nums[i]] != i){
                // 如果在已有的hash表中能够查找到target-nums[i]，并且排除自身，说明能找到target为和的两元素
                res[0] = target - nums[i];
                res[1] = nums[i];
                break;
            }
            // 如果没有找到，就将当前元素添加到hash表中
            a[nums[i]] = i;
        }
        return res;
    }
};
```

通过双指针

~~~cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        // 定义两个指针，分别为左指针和右指针，分别指向首尾
        int left = 0;
        int right = len - 1;
        vector<int> res(2, -1);

        while(left < right && left >= 0 && right < len){
            if(nums[left] + nums[right] > target){
                // 如果两元素之和大于目标值，那么右指针向左移动一位
                --right;
            }
            else if(nums[left] + nums[right] < target){
                // 如果两数之和小于目标值，那么左指针向右移动一位
                ++left;
            }
            else{
                // 找到目标
                res[0] = nums[left];
                res[1] = nums[right];
                break;
            }
        }
        return res;
    }
};
~~~
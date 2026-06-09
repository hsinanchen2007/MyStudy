```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); m[target - nums[i - 1]] = i++){
            if(m.count(nums[i])) return {m[nums[i]], i};
        }
        return {-1, -1};
    }
};
```
- 哈希表解法，时间复杂度O(N)
- 遍历数组，每次都记录：`哈希表[target - 当前数字] = 当前数字的索引`，那么在往后的遍历中如果遇到map的键值包含当前数字的情况，说明之前的某个数字可以和当前数字加和为target，返回俩个数字的索引即可
- 写法上需要清楚C++中for循环的执行顺序：
    - ①初始化i为0
    - ②判断i是否小于数组长度，满足条件执行③，否则跳出循环
    - ③执行for语句对应的`{}`中的代码
    - ④执行`m[target - nums[i - 1]] = i++`
        - a.执行右边的表达式`i++`，记录结果为当前的`i`所拥有的值，并使得此时变量`i`的值递增一步
        - b.计算`target - nums[i - 1]`，此时`i`的值为`用于赋值的值 + 1`，所以`i - 1 = 用于赋值的值`
        - c.写入哈希表
        - 此行代码等同于`m[target - nums[i]] = i; i++;`
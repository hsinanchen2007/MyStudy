### 解题思路
return的第一个参数i我本来写的是m[nums[i]]；但提交过后发现若出现相同元素时，运行出错，比如3，3，target=6；用map映射会有唯一映射map：3->1，答案便出错，因为第2次的3覆盖掉了第1次的。然后参考大佬答案，仔细一想，题目要求的是返回数组下标，假设所求target的两个数组元素（假设为n）是相同大小，而这个元素n有m（m>=2）个，用map存储数据时，第m个元素则会覆盖掉前面m-1个元素。但两数相加，第一个数必定是第1个出现的n，而i则是第1个n出现的下标。故return的第一个参数为i

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map < int , int > m;
        for(int i = 0;i < nums.size();i++){
            m[nums[i]]=i;
        }
        for(int i = 0;i < nums.size();i++){
            if(m.find(target-nums[i])!=m.end()&&m[target-nums[i]]!=i)
            return {i,m[target-nums[i]]};
        }
        return {};
    }
};
```
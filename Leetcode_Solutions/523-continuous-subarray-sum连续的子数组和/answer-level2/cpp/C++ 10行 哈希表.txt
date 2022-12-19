解释在注释中
```
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int i=0, sum=0;
        unordered_map<int, int> m;  //hash记录前i项和的余数及下标i，余数相同则两下标之间的子数组可被k整除
        m[0] = -1;  //起始和为0，下标为-1
        for(; i<nums.size(); i++){
            if(k) sum = (sum + nums[i]) % k; //k不为0时正常求和
            else sum += nums[i]?1:0;         //k为0时只关注nums[]中是否有连续的0
            if(m.find(sum) == m.end()) m[sum] = i;
            else if(i-m[sum] > 1) return true; //map的作用在这里，用下标i判断子数组大小是否至少为2
        }
        return false;
    }
};
```

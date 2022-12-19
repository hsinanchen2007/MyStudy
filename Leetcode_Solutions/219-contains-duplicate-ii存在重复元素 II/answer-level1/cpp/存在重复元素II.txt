时间复杂度为O(N)，空间复杂度为O(N)
用map记录每个数字最后一次出现时的下标，每遍历一个新的数字就查询map中是否有这个数字，如果没有把下表记录到map中；如果有则表示前面已经出现过这个数字，则拿当前下标i与map中保存的下标相减得到距离m，若m小于等于k则返回true，若m大于k则用当前下标替换掉map中的下标继续遍历。

```C++ []
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() < 2 || nums.size() >= 35000) return false;
        map<int, int> M;
        for (int i = 0; i < nums.size(); i++){
            if (M.count(nums[i]) == 0) M[nums[i]] = i;
            else if (i - M[nums[i]] <= k) return true;
            else M[nums[i]] = i;
        }
        return false;
    }
};
```
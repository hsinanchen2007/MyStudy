思路：遍历数组，遇到相等的就返回下标，小于nums[i]的就返回i，如果遍历还没找到，说明target比数组值都大，返回数组长度就ok了。

代码：
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        for (int i=0; i<len; i++){
            if(nums[i] == target) return i;
            else if(target < nums[i]) return i;
        }
      return len;
    }
};
```


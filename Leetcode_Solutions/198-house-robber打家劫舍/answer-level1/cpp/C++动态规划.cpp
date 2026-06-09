思路就是动态规划。已知一个数组，最优方案分为两种可能，最后一家被偷，用max1来表示此时的金额；另一种是最后一家不被偷，用max2表示此时金额。
在此数组后加一个元素，则此时数组的最优方案也分两种可能，最后一家被偷，则可以推出上一个数组最后一家一定不会被偷，即此时的max1为上一次迭代时的max2；同理，最后一家不被偷，则上一个数组最后一家可以不偷也可以偷，即max2 = max(max1, max2).
```
class Solution {
public:
    int rob(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            int temp = max1;
            max1 = max2 + nums[i];
            max2 = max(temp, max2);
        }
        return max(max1, max2);
    }   
};
```


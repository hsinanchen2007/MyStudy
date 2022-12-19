想象一下，每一组两个数字，将每组较小的数字相加。要得到的总和最大

可以假设，较大的数字减去较小的数字就是每组“浪费掉”的，当我们将他们从小到大排列之后，能保证每组浪费掉的数据是最少的。

纯属YY，等大佬证明。
```
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end()); //将数组从小到大排列
        for(int i = 0; i < nums.size(); i = i +2) //将每对的第一位数相加
            ans = ans + nums[i];
        return ans;
    }
};
```
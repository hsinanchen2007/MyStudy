解法一：用一个额外的数组将nums[i]对应的下标值置为1；最后未置为1的即为缺失的数字
```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> temp(nums.size()+1);
        for(int i=0;i<nums.size();i++){
            temp[nums[i]]=1;
        }
        for(int i=0;i<nums.size()+1;i++){
           if(temp[i]==0)
               return i;
        }
        return 1;
    }
};
```
解法二：等差数列求和
用数列和sum减去num中的数据，剩下的数据就是缺失的数据
```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=(nums.size()*(nums.size()+1))/2;
        for(int i=0;i<nums.size();i++)
        {
            sum-=nums[i];
        }
        return sum;
    }
};
//作者：gpe3DBjDS1
//链接：https://leetcode-cn.com/problems/missing-number/solution/que-shi-shu-zi-by-gpe3dbjds1/
```

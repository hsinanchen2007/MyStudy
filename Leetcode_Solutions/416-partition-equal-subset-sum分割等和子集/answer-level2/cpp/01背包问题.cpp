该问题可以等效于经典的01背包问题，数组分割为两个和相等的数组 等价于 需要找出其中和为1/2总数组和的元素，情况为两种：
1. 和是奇数的情况， 此时无法找到两个和相等的数组。return false；
2. 将1/2sum作为背包总容量，数组各个元素看作各物件，值为占用容量，F[i][j]中用true表示能从0-i个数取出容量为j的组合。flase则相反。
  传递关系 F[i][j] = F[i - 1][j] || F[i - 1][j - nums[i - 1]];
  
  可得到列表
  
-   0 1 2 3 4 5 6 7 8 9 10 11 
- 0 Y N N N N N N N N N N  N
- 1 Y Y N N N N N N N N N  N
- 5 Y Y N N N Y N N N N N  N
- 11Y Y N N N Y N N N N N  Y
- 5 Y Y N N N Y Y N N N Y  Y
   最后输出最后一个值。

```
`class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0 ;
        for(auto num : nums)
            sum += num;
        int sum_half;
        if(sum % 2 == 1)return false;
        else sum_half = sum / 2;
        int num_int  = nums.size();
        vector<vector<bool>> F(num_int + 1, vector<bool>(sum_half + 1 ,false));
        for(int i = 0 ; i <num_int + 1; i ++)
            F[i][0] = true;
        for(int i = 1 ; i < num_int + 1 ; i ++)
            for(int j = 1  ; j < sum_half + 1 ; j ++)
            {
                if( j >= nums[i - 1])
                    F[i][j] = F[i - 1][j] || F[i - 1][j - nums[i - 1]];
            }
        return F.back().back();
       
        
        
        
        
    }
};`
```

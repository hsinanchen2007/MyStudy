官方题解是错的
[6,6,6,1,2]
输出
-1
预期结果
0
6 >= 2 * 6?????

[1]
输出
-1
预期结果
0
都没有其他数字了，还怎么至少是数组中每个其他数字的两倍??????   

```cpp

class Solution {
public:

    //找出最大值，再找出第二大值  如果最大值 >= 2 * 第二大值
    int dominantIndex(vector<int>& nums) {
        int size = (int)nums.size();
        //size = 1 找不到其他数字  应该返回-1  但是官方返回0  
        //都没有其他数字了，还怎么至少是数组中每个其他数字的两倍??????
        //不要迷信官方题解，好多错的
        if(size < 2) return 0;
        int max_ = 0;
        int secMax_ = 0;
        //初始化max_和secMax_
        if(nums[0] > nums[1]){
            max_ = 0;
            secMax_ = 1;
        }else{
            //[6,6,6,1,2]
            //相同的  我们认为第二个6大
            max_ = 1;
            secMax_ = 0;
        }
        for(int i = 2;i < size ;i++){
            //更新max_ secMax_
            if(nums[i] > nums[max_]){
                secMax_ = max_;
                max_ = i;
                continue;
            }
            //nums[i] 大于  第二大值    小于 最大值
            if(nums[i] > nums[secMax_] && nums[i] < nums[max_]){
                //更新 secMax_
                secMax_ = i;
            }
        }
        return nums[max_] >= 2 * nums[secMax_] ? max_ : -1;
    }
};
```
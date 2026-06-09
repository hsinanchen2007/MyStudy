### 解题思路
    该问题可以转换为：找到一个数，使数组中其他元素与其差的绝对值之和最小
    可以先将数组排序，取出中位数，再求其它数与其差的绝对值之和

### 代码

```cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //判断特殊输入条件
        if(nums.empty())
            return 0;
        
        //运用库函数进行排序
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        //获得中位数
        //n是奇数
        if(n & 0x1) 
            return Add(nums[n/2], nums);
        //n是偶数时要取两种情况的最小值
        return min(Add(nums[n/2], nums), Add(nums[n/2 - 1], nums));
    }
    
    //计算差的绝对值之和
    int Add(int num, vector<int>& nums){
        int res = 0;
        for(auto i : nums)
            res += abs(num - i);
        
        return res;
    }
};
```
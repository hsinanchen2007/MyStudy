### 解题思路
本题总体思路：
    如果数组长度小于3，肯定能成功。
    如果遇到前一个数大于后一个数，则改变大小，flag+1，如果改变超过1次，则说明不能成功，返回false。

从第一个数i遍历到倒数第二个数，如果前一个数大于后一个数，这个题就是两条主线：
    1.i为第一个数，则让nums[i]=nums[i+1];
    2.i为中间数，则有三种情况：
        a.如[1 3 2],nums[i-1]<nums[i+1],则让nums[i] = nums[i+1];
        b.如[2 3 1],nums[i-1]>nums[i+1],则让nums[i+1] = nums[i];
        c.如[1 3 1],[3 2 1]，则又分为两种情况：
            1.如[3 2 1], nums[i-1]>nums[i]，则让nums[i-1] = nums[i];
            2.如[1 3 1], nums[i-1]<nums[i],则让nums[i] = nums[i-1].

![捕获.PNG](https://pic.leetcode-cn.com/a5feb40cfd95cc9b98842e77574abb796cd0bbc6ae1b5909565dd2c7d47d4784-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```cpp
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int flag=0;
        if(nums.size()<3)  return true;        
        for(int i=0 ; i<nums.size()-1 ; i++){
            if(nums[i]>nums[i+1]){
                flag++;
                if(flag>1)  break;
                if(i==0)    nums[i] = nums[i+1];    
                else{
                    if(nums[i-1]<nums[i+1]) nums[i] = nums[i+1];
                    if(nums[i-1]>nums[i+1]) nums[i+1] = nums[i];
                    else{
                        if(nums[i-1]>nums[i])   nums[i-1] = nums[i];
                        else    nums[i] = nums[i-1];
                    }
                }
            }
        }
        return flag<=1;
    }
};
```
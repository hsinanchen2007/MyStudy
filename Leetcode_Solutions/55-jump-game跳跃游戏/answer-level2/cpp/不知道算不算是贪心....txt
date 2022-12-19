### 解题思路
![X}_8P5`H2A_PAQX1NK}AKJ0.png](https://pic.leetcode-cn.com/6c81e4468ffa561018094d14826b805b7d18766b03b25bba79230924a9404c52-X%7D_8P5%60H2A_PAQX1NK%7DAKJ0.png)

只要数组中没有0，一定能到最后。
所以就是找出数组中值为0的位置，往前遍历，用数组下标和数组值相加，若是和超过0所在位置，则可以越过0，若是不行，则失败。
还有考虑特殊结果，即最后一位为0时，往前遍历，数组值和下标值相加可以等于最后一位下标。
还有就是数组长度只有一位时，始终成功

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return  true;
        int flag=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                for(int j=i-1;j>=0;j--){
                    if(i==nums.size()-1){
                        if(nums[j]+j>=i){
                            flag=1;
                            break;
                        } 
                    }else{
                        if(nums[j]+j>i){
                            flag=1;
                            break;
                        } 
                    }
                }
                if(flag==0) return false;
            }
            flag=0;
        }
        return true;
    }
};
```
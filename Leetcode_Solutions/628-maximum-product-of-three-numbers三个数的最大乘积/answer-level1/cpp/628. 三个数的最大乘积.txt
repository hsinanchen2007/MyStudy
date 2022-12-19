## 找出前三大的数和前二小的数
**最大乘积等于以下其一：
1. 前三大的数的乘积
2. 前二小的数与第一大的数的乘积**
```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int len = nums.size();
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for (int i=0; i<len; i++){
            if (nums[i] <= min1){
                min2 = min1;
                min1 = nums[i];
            } 
            else if(nums[i] <= min2){  
                min2 = nums[i];
            }
            if(nums[i] >= max1){   
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            } 
            else if(nums[i] >= max2){   
                max3 = max2;
                max2 = nums[i];
            } 
            else if(nums[i] >= max3){   
                max3 = nums[i];
            }
        }
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};
```
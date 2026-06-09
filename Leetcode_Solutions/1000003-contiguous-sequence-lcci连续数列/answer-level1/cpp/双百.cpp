### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max1=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>max1){
                max1=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return max1;
    }
};
```
### 解题思路
获得一个序列所有左边的元素的乘积和与右边所有元素的乘积，列2张表，返回的是左边的乘积乘以右边的乘积。

### 代码

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int* leftProduct = new int[nums.size()];
        int* rightProduct = new int[nums.size()];
        leftProduct[0] = rightProduct[nums.size()-1] = 1;
        for(int i = 1;i<nums.size();i++){
            leftProduct[i] = leftProduct[i-1] * nums[i-1];
        }
        for(int i = nums.size()-2;i>=0;i--){
            rightProduct[i] = rightProduct[i+1] * nums[i+1];
        }
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            result.push_back(leftProduct[i]*rightProduct[i]);
        }
        return result;
    }
};
```
### 解题思路
本来的想法是创建两个数组，分别记录i点左边所有数的乘积，即a1[i] = nums[0] * nums[1] * ... *nums[i-1] 
另一个数组记录右边所有数的乘积，最后结果汇总这两个数组即可，即res[i] = ai[i-1] * a2[i+1]

后面发现并不需要数组，只需要往右扫一遍，先记录某个位置左边所有乘积，然后往左扫一遍，记录某个位置右边所有乘积，最后相乘即可
### 代码

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),1);
        int left = 1;
        for(int i = 1;i < nums.size();++i){
            left *= nums[i-1];
            res[i] *= left;
        }
        int right = 1;
        for(int i = nums.size() - 2;i >= 0;--i){
            right *= nums[i+1];
            res[i] *= right;
        }
        return res;
    }
};
```
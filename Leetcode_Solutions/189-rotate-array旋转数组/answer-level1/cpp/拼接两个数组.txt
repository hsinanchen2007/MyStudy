### 解题思路
拼接两个数组
### 代码

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if((nums.size() <= 1)||(k == 0)){
            return;
        }
        //如何移位的长度大于输入数组的长度，进行取余操作
        if(k>nums.size()){
            k = k%nums.size();
        }
        //拼接两个数组
        vector<int> vec;//vec
        vec.insert(vec.end(),nums.begin(),nums.end());//将nums压入
        vec.insert(vec.end(),nums.begin(),nums.end());//将nums压入
        for(int i = 0;i<=nums.size()-1;i++){
            nums[nums.size()-1-i] = vec[2*nums.size()-1-k-i];
        }
    }
};
```
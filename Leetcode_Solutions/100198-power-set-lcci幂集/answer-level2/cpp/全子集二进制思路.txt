### 解题思路
事先知道集合数量，利用一个长度位集合数量的二进制位串作为指示字符串，当对应位置为1的时候，取出对应元素
### 代码

```cpp
class Solution {
public:
    vector<int> getset(int n, vector<int> nums){
        vector<int> v;
        int i = 0;
        while(n){
            int res = n%2;
            if(res == 1)    v.push_back(nums[i]);
            n/=2;
            i++;
        }
        return v;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        for(int i = 0;i < pow(2, nums.size());i++){
            v.push_back(getset(i, nums));
        }
        return v;
    }
};
```
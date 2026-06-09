### 双数组法
使用两个数组，分别记录当前位置i前面和后面所有数的乘积，最后再遍历一次两个数组，并算出结果。
### 时间/空间复杂度n
时间：O（n）
空间：O（n）
### 代码

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prev(n,1);
        vector<int> next(n,1);
        for(int i=1;i<n;++i){
            prev[i]=prev[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;--i){
            next[i]=next[i+1]*nums[i+1];
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;++i){
            ans[i]=prev[i]*next[i];
        }
        return ans;
    }
};
```
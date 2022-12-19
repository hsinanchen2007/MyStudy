### 解题思路
![image.png](https://pic.leetcode-cn.com/edd7c981697048a116a4c7fec74f002c13c3497f016badc022ab491f64dd80f8-image.png)


### 代码

```cpp
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        sort(&nums[0],&nums[0]+nums.size());
        int maxdif=0;
        for(int i=1;i<nums.size();i++)   maxdif=max(maxdif,abs(nums[i]-nums[i-1]));
        return maxdif;
    }
};
```
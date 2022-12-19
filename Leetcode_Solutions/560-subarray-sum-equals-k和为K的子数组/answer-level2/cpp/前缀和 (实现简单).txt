### 解题思路
1. 假如存在区间`[left,right]`，使得在`[left,right]`这个区间的子数组的和为`k`。换句话说，就是前`right`项和减去前`left`项和等于`k`，即前`left`项和等于前`right`项和减去`k`。
2. 可以这样做，在扫描数组的同时，假设当前扫到第`i`位，记录它的前`i`项和`sum`，用该和减去`k`，即`sum-k`，判断`sum-k`是否为某个位置的前`n`项和，若是，更新统计量。

  
非常感谢用户[@zkuestc](/u/zkuestc/)提出的宝贵意见：[l,r]中l的确容易看成是1.现将[l,r] 改成[left, right]!


### 代码

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i: nums){
            sum += i;
            if(mp.find(sum-k) != mp.end()) ans += mp[sum-k];
            mp[sum] ++;
        }
        return ans;
    }
};
```
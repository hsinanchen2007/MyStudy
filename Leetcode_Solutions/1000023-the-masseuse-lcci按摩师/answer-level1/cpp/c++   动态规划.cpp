### 解题思路
***动态规划***
思路：若共有n场约会，从第1场开始，算出截止到每一场的最佳选择。
比如截止到第1场，最佳选择就是第1场
截止到第2场，最佳选择就是max(第1场， 第2场)
截止到第3场，有两种可能，第一种是截止到第2场时的选择；第二种是截止到第1场时的选择加上第3场。最佳选择是两种可能中更大的那一个。抽象为动归公式为：`v[i] = max(v[i-1], v[i-2]+nums[i])`
自己手动模拟一下更有助于理解。

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        int n = nums.size();
        if(n==0)    return 0;
        else if(n==1)    return nums[0];
        else if(n==2)   return max(nums[0], nums[1]);
        
        vector<int> v(n);
        v[0] = nums[0];
        v[1] = max(nums[0], nums[1]);
        for(int i=2; i<n; i++) {
            v[i] = max(v[i-1], v[i-2]+nums[i]);
        }
        return v[n-1];
    }
};
```


时间复杂度为O(n),空间复杂度为O(n)。
其实空间复杂度还可以继续优化，由公式`v[i] = max(v[i-1], v[i-2]+nums[i])`可知，在计算v[i]时，nums数组中i之前的已经用不到了。
比如nums=[1,10,100]。当计算到v[2]时，用到的是v[0],v[1],nums[2]，所以我们可以用nums[0],nums[1]来存储v[0],v[1]。
这样我们可以不用定义v,直接在nums上进行计算。公式为：`nums[i] = max(nums[i-1], nums[i-2]+nums[i])`
结合下面代码进行手动模拟更有助于理解。

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        int n = nums.size();
        if(n==0)    return 0;
        else if(n==1)    return nums[0];
        else if(n==2)   return max(nums[0], nums[1]);
        
        nums[1] = max(nums[0], nums[1]);
        for(int i=2; i<n; i++) {
            nums[i] = max(nums[i-1], nums[i-2]+nums[i]);
        }
        return nums[n-1];
    }
};
```

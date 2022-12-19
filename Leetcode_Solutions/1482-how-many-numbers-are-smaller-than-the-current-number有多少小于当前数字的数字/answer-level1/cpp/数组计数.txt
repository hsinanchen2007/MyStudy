### 解题思路
数组计数

### 代码

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int a[101];
        vector<int> ans;
        for ( int i = 0; i < 101; i++ )
            {a[i] = 0;}
        for (int i: nums)
            {a[i]++;}
        for (int i = 1; i < 101; i++)
            {a[i] += a[i-1];}
        for (int i : nums)
            {if (i) {ans.push_back(a[i-1]);}
                else{ans.push_back(0);}}
        return ans;
    }
};
```
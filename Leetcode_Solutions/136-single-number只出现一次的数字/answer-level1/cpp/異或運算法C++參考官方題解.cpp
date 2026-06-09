### 解题思路
利用異或運算性質：
1. 交換律，a^b=b^a
2. 結合律 (a^b)^c=a^(b^c)
3. 兩個同樣的數異或則清零，即a^a=0
因此，綫性遍歷，從頭計算到尾部，最後剩下的即為答案

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        ans^=nums[i];
        return ans;
    }
};
```
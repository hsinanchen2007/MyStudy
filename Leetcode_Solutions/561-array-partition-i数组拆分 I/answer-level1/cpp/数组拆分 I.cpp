### 解题思路
解法一（排序）：
要使从1 到 n 的 min(ai, bi) 总和最大，只要后一个数对的第一个数大于前一个数对的第二个数，即a[i+1] > b[i]。
因此可以先对数组进行排序，则第0，2，4，……，2n-2个元素即为每个数对中最小的数，且总和最大。

### 代码

```cpp
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;

        for(int i=0; i<nums.size(); i+=2){
            ans += nums[i];
        }

        return ans;
    }
};
```
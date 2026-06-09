### 解题思路
暴力解法：
1.判断字符串长度和K是否合理；
2.利用sort排序；
3.输出第k个结果

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       int res = 0;
       int numSize = int (nums.size());
       if(numSize == 0 || k > numSize) {
           return 0;
       }
       sort(nums.begin(),nums.end());
       res = nums[numSize - k];
       return res;
        
    }
};
```
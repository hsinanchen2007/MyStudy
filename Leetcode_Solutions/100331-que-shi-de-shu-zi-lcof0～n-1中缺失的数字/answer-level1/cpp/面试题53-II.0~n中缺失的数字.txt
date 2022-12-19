### 解题思路
- 核心要点：二分查找思想，注意中点值判断条件nums[m]!=m，right=m-1，最终left的值即为结果
- 执行用时 :44 ms, 在所有 C++ 提交中击败了9.13%的用户
- 内存消耗 :17 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        int m;
        while(left<=right){
            m=(left+right)/2;
            if(nums[m]!=m)right=m-1;
            else left=m+1;
        }
        return left;
    }
};
```
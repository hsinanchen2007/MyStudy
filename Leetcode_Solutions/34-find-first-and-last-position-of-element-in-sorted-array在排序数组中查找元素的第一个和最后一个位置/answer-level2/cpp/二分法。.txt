### 解题思路

看到题目要求的O(logn)就想到二分法。找到目标数后再向左右延伸。


### 代码

```cpp
class Solution {
public:

    // 执行用时 :8 ms, 在所有 C++ 提交中击败了86.62% 的用户
    // 内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        if(nums.size()==0) return res;//必须返回一个vector向量， 直接返回{-1, -1}不行。
        int start = 0, end = nums.size()-1;
        int first = -1, last = -1;
        while(start<=end){
            int mid = (end-start)/2+start;
            if(nums[mid]==target){//找到和target相同的数。
                first = mid;
                last = mid;
                while(first>start&&nums[first-1]==target) --first;//向左延伸
                while(last<end&&nums[last+1]==target) ++last;//向右延伸。
                break;
            }
            if(nums[mid]>target) end = mid-1;
            if(nums[mid]<target) start = mid+1;
        }
        res[0] = first, res[1] = last;
        return res;
    }
};
```
### 解题思路
此处撰写解题思路
二分查找到了target后，while前后走，直到找到前后index。但这样的话，如果中间全是相等的值，可能也要很久 O(n)。没有达到二分O(logn) 的效果。其实找到target后，在前后都还可以再进行二分。
### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target){
        int index1 = -1, index2 = -1;
        vector<int> res;
        res.push_back(index1);
        res.push_back(index2);
        // then
        if(nums.size() <= 0) return res;
        int start = 0, end = nums.size()-1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == nums[mid]){
                index1 = mid;
                index2 = mid;
                while ( index1 >=1 && target == nums[index1-1]) {
                    index1 = index1 - 1;
                }
                while (index2 < nums.size()-1 && target == nums[index2+1]) {
                    index2 = index2 + 1;
                }
                res[0] = index1;
                res[1] = index2;
                return res;
            }
            else if(target > nums[mid]) start = mid+1;
            else end = mid-1;
        }
        return res;
    }
};
```
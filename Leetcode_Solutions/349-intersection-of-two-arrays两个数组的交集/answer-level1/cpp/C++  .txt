### 解题思路
执行用时 :8 ms, 在所有 C++ 提交中击败了 83.66%的用户
内存消耗 :10.6 MB, 在所有 C++ 提交中击败了5.37%的用户
将最长的vector转为set去重，再轮询短的vector，若找到该元素，则将该元素放入输出vector中，并将set中的元素擦除

### 代码

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> nums;
        vector<int> result;

        if(nums1.size()>nums2.size()){
            for(auto number : nums1) nums.insert(number);
            for(auto number : nums2){
                if(nums.find(number)!=nums.end()){
                    result.push_back(number);
                    nums.erase(number);
                } 
            }
        }
        else{
            for(auto number : nums2) nums.insert(number);
            for(auto number : nums1){
                if(nums.find(number)!=nums.end()){
                    result.push_back(number);
                    nums.erase(number);
                } 
            }
        }
        
        return result;
    }
};
```
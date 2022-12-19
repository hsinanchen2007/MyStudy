```
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> unmap; //键值对：key是数字自身，value是出现次数
        // sort(nums.begin(), nums.end());
        int midSize = nums.size() / 2;
        int width = nums.size();
        for(int i = 0; i < width; ++i) {
            unmap[nums[i]] += 1; //这是一个很好用的技巧，用以统计元素及其出现的次数
            if ( unmap[nums[i]] > midSize ) return nums[i];// 找到满足要求的元素就返回，这样不会超时；如果在这个循环结束后再找满足条件的元素，那就要再遍历一次，就会超时
        }
        
        return 0;
    }

};
```

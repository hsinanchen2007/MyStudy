### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    // mid+1，mid-1能让效率提高非常多，没有+1和-1的话，会超出时间限制
    int search(vector<int>& nums, int target) {
        int mid, left = 0, right = nums.size()-1;
        while (left <= right) {
            // 这种求中值可以防止(l+r)/2造成溢出，因为l+r有可能超出int的整数范围
            mid = left + (right-left)/2;
            if (target == nums[mid]) return mid;
            if (target > nums[mid]) left = mid+1;
            else right = mid-1;
        }
        return -1;
    }
};


#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int mid, left = 0, right = nums.size()-1;
    while (left <= right) {
        mid = left + (right-left)/2;
        if (target == nums[mid]) return mid;
        if (target > nums[mid]) left = mid+1;
        else right = mid-1;
    }
    return -1;
}

int main() {
    vector<int> nums = {-1,0,3,5,9,12};
    cout << search(nums, 9) << endl;
}


```
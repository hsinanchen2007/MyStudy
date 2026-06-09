### 解题思路
总感觉这道题不想ease难度。。。

### 代码

```cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int N = nums.size();
        int st = -1, end = -1;
        for(int i = 0; i < N-1; i++){
            if(nums[i] > nums[i+1]){
                st = i;
                break;
            }
        }
        for(int i = N-1; i > 0; i--){
            if(nums[i-1] > nums[i]){
                end = i;
                break;
            }
        }
        if(st == -1 || end == -1) return 0;
        int cur_max = INT_MIN, cur_min = INT_MAX;
        for(int i = st; i <= end; i++){
            cur_max = max(cur_max, nums[i]);
            cur_min = min(cur_min, nums[i]);
        }

        int left = upper_bound(nums, 0, st, cur_min);
        int right = lower_bound(nums, end, N, cur_max)-1;
        // cout << nums[left] << " " << nums[right];
        return right-left+1;

    }

    int upper_bound(const vector<int> &nums, int left, int right, int val){
        int st = left, end = right;
        while(st < end){
            int mid = st + (end-st) / 2;
            if(nums[mid] <= val) st = mid+1;
            else end = mid;
        }
        return st;
    }

    int lower_bound(const vector<int> &nums, int left, int right, int val){
        int st = left, end = right;
        while(st < end){
            int mid = st + (end-st)/2;
            if(nums[mid] < val) st = mid+1;
            else end = mid;
        }
        return st;
    }
};
```
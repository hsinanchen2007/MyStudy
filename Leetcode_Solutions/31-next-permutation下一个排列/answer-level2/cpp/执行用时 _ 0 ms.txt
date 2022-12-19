### 解题思路
按照要求，需要找一个比当前顺序组成的数大的数，而且这个数还得是大的数中最少的那个。因此，算法分为两步：
1、找到一个更大的数。可以通过从后向前找第一个降序的数的下标i,再从数组末尾开始，找到第一个比nums[i]大的数的下标j，交换nums[i]和nums[j]；
2、使大的最少，从i+1开始，对nums升序排列。升序排列是使数列达到最小的组合。

### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int pos = 0, size = nums.size();
        bool down = false;
        for(pos = size - 1; pos >= 0 && pos - 1 >= 0; --pos){
            if(nums[pos] > nums[pos - 1]){
                down = true;
                break;
            }
        }
        if(down){
            int j = size - 1;
            for(; j >= pos; --j){
                if(nums[j] > nums[pos - 1]){
                    swap(nums[j], nums[pos - 1]);
                    for(int m = pos, n = size - 1; m < n; ++m, --n)
                        swap(nums[m], nums[n]);
                    break;
                }
            }
        } 
        else{
            reverse(nums.begin(), nums.end());
        }
    }
};
```
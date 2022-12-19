### 解题思路
题目给的测试用例有点让人容易忘了很容易想到的 132这种case
所以比123->132这种要复杂一些

### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      if(nums.size() < 2)  return;
      //01234 i
      //13210 find i = 1
      //10123 sort i = 1 j = 1, nums[i - 1] = 1
      //20113 swap i - 1 and j = 3 ,first num larger than nums[i - 1]

      //find first nums[i] lager than nums[i-1]
      int i;
      for(i = nums.size() - 1; i > 0 ; i--){
        if(nums[i] > nums[i - 1]){
          break;
        }
      } 
      //sort nums[i] to nums end
      sort(nums.begin() + i, nums.end());

      if(i > 0){
        for(int j = i; j < nums.size(); j++){
          if(nums[j] > nums[i - 1]){
            swap(nums[j], nums[i - 1]);
            return;
          }
        }
      }

      //i == 0
      return;   
    }
};
```
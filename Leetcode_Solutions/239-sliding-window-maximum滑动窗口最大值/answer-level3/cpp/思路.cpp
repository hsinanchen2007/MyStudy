### 解题思路
deque的使用
部分思路有点像最大栈的做法

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      if(nums.size() == 0 || k == 1)  return nums;
      vector<int> res;
      deque<int> window;

      for(int i = 0; i < k; i++){
        while(!window.empty() && nums[i] > nums[window.back()]){
          window.pop_back();
        }
        window.push_back(i);
      }
      res.push_back(nums[window.front()]);

      for(int i = k; i < nums.size(); i++){
        while(!window.empty() && i - k + 1 > window.front()){
          window.pop_front();
        }
          
        while(!window.empty() && nums[i] > nums[window.back()]){
          window.pop_back();
        }
        window.push_back(i);
        res.push_back(nums[window.front()]);
      }

      return res;
    }
};
```
### 解题思路
本来想着试试大顶堆，结果在删除最后一个元素时卡了，改成了vector 效率感人，稍后试试双队列的

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         if (nums.size() == 0) {
            return nums;
        }
        vector<int> result;
        vector<int> window;
        for (int i = 0; i<k; i++) {
            window.push_back(nums[i]);
        }
        for (int i = k; i<nums.size()+1; i++) {
            int j = *max_element(begin(window), end(window));
            result.push_back(j);
            vector<int>::iterator head = window.begin();
            if (i<nums.size()) {
                window.erase(head);
                window.push_back(nums[i]);
            }
        }
        
        return result;
    }
};
```
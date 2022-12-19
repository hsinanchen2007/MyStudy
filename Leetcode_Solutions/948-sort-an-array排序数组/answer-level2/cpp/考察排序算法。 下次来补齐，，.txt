### 解题思路
目前直接sort。  下次来补齐各种排序算法。！

### 代码

```cpp
class Solution {
public:
    // 执行用时 :116 ms, 在所有 C++ 提交中击败了10.82% 的用户
    // 内存消耗 :15.9 MB, 在所有 C++ 提交中击败了21.09%的用户
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()<2) return nums;
        sort(nums.begin(), nums.end());//直接调用库函数sort .include<algorithm>
        return nums;
    }

    



};
```
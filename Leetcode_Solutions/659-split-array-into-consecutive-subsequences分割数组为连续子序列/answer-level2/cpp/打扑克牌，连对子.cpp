### 解题思路
因为是有序的，所以我们不需要通过优先队列重新排列。建立两个HashMap， freq用来保存数字与出现次数的映射，need用来保存数字与该数字期望用来做连对的次数。
很巧妙的方法。
### 代码

```cpp
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, need;
        for (int num : nums) ++freq[num];
        for (int num : nums) {
            if (freq[num] == 0) continue;
            if (need[num] > 0) {
                --need[num];
                ++need[num + 1];
            } else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                --freq[num + 1];
                --freq[num + 2];
                ++need[num + 3];
            } else return false;
            --freq[num];
        }
        return true;
    }
};
```
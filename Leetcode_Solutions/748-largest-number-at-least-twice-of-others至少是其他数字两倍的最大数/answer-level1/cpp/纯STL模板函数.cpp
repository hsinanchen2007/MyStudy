查找最大值下标->移除最大值->判断剩余内容

```
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int> copy(nums);
        auto maxPos = max_element(copy.begin(), copy.end()); // 寻找最大值位置
        if (maxPos == copy.end()) return true;
        int maxVal = *maxPos; // 获取最大值
        int maxIndex = maxPos - copy.begin(); // 获取最大值索引
        copy.erase(maxPos); // 移除最大值
        return all_of(copy.begin(), copy.end(), [&maxVal](int v){ return v * 2 <= maxVal;}) ? maxIndex : -1;
    }
};
```

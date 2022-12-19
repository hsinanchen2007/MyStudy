使用有序map，key 为出现的元素，value 为元素出现的次数，具体见注释。

```
class Solution {
   public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        // 元素的个数不是 k 的倍数，直接返回 false
        if (nums.size() % k != 0) return false; 

        map<int, int> mm;
        for (int i : nums) mm[i]++;

        while (!mm.empty()) {
            int count = 0;
            int pre = 0;
            for (map<int, int>::iterator it = mm.begin(); it != mm.end();) {
                if (count == k) break;
                if (count == 0 || it->first - pre == 1) {
                    // 更新 pre 和 count
                    pre = it->first;
                    count++;
                    // 元素的个数减 1，如果剩余的个数为 0，删除这个元素
                    it->second--;
                    if (it->second == 0) mm.erase(it++);
                    else it++;
                } else { // 当前这个数与前一个数的差不是 1，不符合条件，返回 false
                    return false;
                }
            }
            if (count != k) return false; // 如果个数小于 k 个，不符合条件
        }
        return true;
    }
};
```

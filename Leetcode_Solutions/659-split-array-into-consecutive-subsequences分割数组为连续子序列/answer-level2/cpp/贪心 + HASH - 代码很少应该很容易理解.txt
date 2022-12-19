### 解题思路

思路：贪心
1、计算表内每一个值的个数，用HASH存储，然后拿HASH表进行遍历即可
2、每次尽可能的去消耗数值，直到后面的值个数小于前面值个数时停止，检查连续序列个数是否超过3个

112ms 57.3M
--- wangtao HW-2020/3/18

### 代码

```cpp
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> hash;
        vector<pair<int, int>> data;
        if (nums.size() < 3) return false;

        for (auto c : nums) {
            hash[c]++;
        }
        for (auto c : hash) {
            data.push_back({c.first, c.second});
        }
        int i = 0;
        while (i < data.size() - 1) {
            if (data[i].second == 0) {
                i++;
                continue;
            }
            int k = i;
            int count = 1;
            while (k < data.size()-1 && data[k].first + 1 == data[k+1].first && data[k].second <= data[k+1].second) {
                count++;
                data[k].second--;
                k++;
            }
            if (count < 3) return false;
            data[k].second--;
        }
        return data[i].second == 0;
    }
};
```
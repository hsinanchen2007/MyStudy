### 解题思路

有几个小的地方需要考虑的：
- 最先考虑到的方法应该是将数组展开为哈希容器，键名为出现的数字，键值为出现的次数；
- 当总的次数，也就是数组的大小都无法被K整除时，这是第一个被返回false的场景；
- 以迭代次数小于size为循环条件，找到每次最小值，并更新容器中的键值对。

### 代码

```cpp
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int size = nums.size();
        if(size % k != 0) {
            return false;
        }
        std::sort(nums.begin(), nums.end());
        unordered_map<int, int> up;
        for(auto &n : nums) {
            up[n]++;
        }

        vector<vector<int>> ans;
        int ii = 0;
        while(ii <= size) {
            int min_number = pow(10, 9);
            vector<int> row;
            // Find min element in unordered_map?
            for(auto &n : up){
                min_number = std::min(min_number, n.first);
            }
            // cout << "min_number: " << min_number << endl;
            if(min_number == pow(10, 9)) break;
            // Start and Max iterator value 
            for(int i = min_number; i <= min_number + k - 1; i++) {
                // cout << " iter number: " << i << endl;
                auto ur = up.find(i);
                if(ur != up.end() && ur->second > 0){
                    row.push_back(i);
                    up[i] -= 1;
                    // cout << "found, key:" << i << " value:" << up[i] << endl;
                    if(up.at(i) <= 0) {
                        up.erase(ur);
                    }
                } else {
                    return false;
                }
            }
            ii += k;
            ans.push_back(row);
        }

        // for(auto &n : ans) {
        //     for(auto &m: n) {
        //         cout << m << endl;
        //     }
        // }

        return true;
    }
};
```
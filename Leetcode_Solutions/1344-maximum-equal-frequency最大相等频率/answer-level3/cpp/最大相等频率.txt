### 解题思路
map+set，对set的操作比较麻烦，搞了一天才好

### 代码

```cpp
class Solution {
public:
    int maxEqualFreq(vector<int>& nums)
    {
        int result = 0;
        unordered_map<int, int> freqMap;
        multiset<pair<int, int>, Cmp> sortFreq;

        for (int i = 0; i < nums.size(); ++i) {
            freqMap[nums[i]]++;
            
            auto findIt = sortFreq.equal_range(make_pair(nums[i], freqMap[nums[i]] - 1));
            while (findIt.first != findIt.second) {
                if (findIt.first->first == nums[i]) {
                    findIt.first = sortFreq.erase(findIt.first);
                    break;
                } else {
                    ++(findIt.first);
                }
            }

            sortFreq.insert(make_pair(nums[i], freqMap[nums[i]]));

            if (IsMaxFreqSubArray(sortFreq)) {
                result = max(result, i + 1);
            }
        }

        return result;
    }
private:
    struct Cmp {
        bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
            return a.second < b.second;
        }
    };

    bool IsMaxFreqSubArray(const multiset<pair<int, int>, Cmp>& sortSet)
    {
        if (sortSet.size() == 1) {
            return true;
        }

        auto frontIt = sortSet.begin();
        auto secondIt = next(sortSet.begin(), 1);
        auto backIt = prev(sortSet.end(), 1);
        auto backSecondIt = prev(sortSet.end(), 2);

        if ((*frontIt).second == 1 && (*secondIt).second == (*backIt).second) {
            return true;
        }

        if ((*frontIt).second == (*backSecondIt).second && (*backIt).second == (*frontIt).second + 1) {
            return true;
        }

        return false;
    }

    void PrintFreqSet(const multiset<pair<int, int>, Cmp>& sortSet)
    {
        cout << "the sort set is : " << endl;
        for (auto each : sortSet) {
            cout << each.first << "," << each.second << endl;
        }
    }
};
```
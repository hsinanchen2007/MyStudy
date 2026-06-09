### 解题思路
先建立num和times的哈希表，然后在建立times和num数组的哈希表， 利用map的有序性进行操作；同时也需要注意可以将time和num放到vector里面，然后排序输出。

### 代码

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> numsTimes;
        for (auto num : nums) {
            if (numsTimes.find(num) == numsTimes.end()) {
                numsTimes[num] = 1;
            } else {
                numsTimes[num]++;
            }
        }
        map<int, vector<int>> timesNum;
        for (auto pNumTime = numsTimes.begin(); pNumTime != numsTimes.end(); pNumTime++) {
            timesNum[pNumTime->second].push_back(pNumTime->first);
        }
        vector<int> results;
        auto pTimesNum = timesNum.rbegin();
        int index = 0;
        while(index < k) {
            for (auto num : pTimesNum->second) {
                results.push_back(num);
                index++;
            }
            pTimesNum++;
        }
        return results;
    }
};
```
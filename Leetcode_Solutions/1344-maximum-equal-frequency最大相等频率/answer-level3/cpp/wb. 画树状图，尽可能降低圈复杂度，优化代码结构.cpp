### 解题思路

### 代码

```cpp
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        // 线性时间内统计所有元素出现频率的种类
        map<int, int> mValCnt;
        map<int, set<int>> mFreqVal;
        int freqCnt;
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (mValCnt.find(num) == mValCnt.end()) {
                mFreqVal[1].insert(num);
            } else {
                int k = mValCnt[num];
                if (mFreqVal[k].size() == 1) {
                    mFreqVal.erase(k);
                } else {
                    mFreqVal[k].erase(num);
                }
                mFreqVal[k + 1].insert(num);                
            }
            mValCnt[num]++;
            freqCnt = mFreqVal.size();

            auto it = mFreqVal.begin(); 
            if (freqCnt == 1) {
                if (it->first == 1 || it->second.size() == 1) {
                    len = max(len, i + 1);
                }
            } else if (freqCnt == 2) {
                if (it->second.size() == 1 && it->first == 1) {
                    len = max(len, i + 1);
                    continue;
                }
                it++;
                if (it->second.size() == 1 && it->first == mFreqVal.begin()->first + 1) {
                    len = max(len, i + 1);
                }
            } else {
                
            }
        }
        return len;
    };
};
```
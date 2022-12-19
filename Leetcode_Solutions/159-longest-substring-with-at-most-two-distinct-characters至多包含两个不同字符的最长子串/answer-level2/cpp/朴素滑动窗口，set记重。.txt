### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int maxL = 1;
        for (int ptr = 0; ptr < s.size(); ptr++) {
            cout << "---------"<< s[ptr]<<"----------" << endl;
            int scan = ptr +1;
            set<char> distinctCount;
            distinctCount.emplace(s[ptr]);
            int lengthCount = 1;
            while (distinctCount.size() <= 2 && scan < s.size()) {
                cout << s[scan] <<", ";
                if (distinctCount.find(s[scan]) == distinctCount.end() ) {
                    distinctCount.emplace(s[scan]);
                }
                lengthCount++;
                scan++;
            }
            if(distinctCount.size() > 2) {
                lengthCount--;
            }
            cout << endl;
            maxL = lengthCount > maxL? lengthCount : maxL;
            cout << "maxL: "<<maxL << endl;
        }
        return maxL;
    }
};
```
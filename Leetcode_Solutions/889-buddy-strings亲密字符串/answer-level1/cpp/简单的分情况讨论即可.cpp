### 解题思路
首先统计A与B有差异的位数count
然后分情况讨论：
（1）count == 2：此时说明A与B有2位不同，那么按题意还需要保证A交换有差异的2位字母后，A==B
（2）count == 0: 说明A==B, 那么此时这种情况也是满足条件的，如A=B=“aaaa”, A=B="abab"。其规律是字母出现的次数都是偶数，才能保证交换2位后还是原词。
（3）其他情况：都不满足条件 

### 代码

```cpp
class Solution {
public:
    bool buddyStrings(string A, string B) {
        int len1 = A.size();
        int len2 = B.size();
        if (len1 != len2 || len1 < 2) {
            return false;
        }
        // 先统计A与B有差异的位数
        vector<pair<char, char>> diffCount;
        for (int i = 0; i < len1; i++) {
            if (A[i] != B[i]) {
                diffCount.push_back(make_pair(A[i], B[i]));
            }
        }
        //分情况讨论
        // 1. A!=B,且差异的位数=2，那么差异位的字母按题意交换后应该能让A==B才符合条件
        if (diffCount.size() == 2 &&
            diffCount[0].first == diffCount[1].second &&
            diffCount[1].first == diffCount[0].second) {
            return true;
        }

        //2. A==B时，必须保证A/B中每个字母都出现偶数次，才能交换A的2个字母位置后还是A
        if (diffCount.size() == 0) {
            char counter[26] = {0};
            for (int i = 0; i < len1; i++) {
                counter[A[i] - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (counter[i] % 2 != 0) {
                    return false;
                }
            }
            return true;
        }
        // 3. 其他情况都不满足条件
        return false;
    }
};
```
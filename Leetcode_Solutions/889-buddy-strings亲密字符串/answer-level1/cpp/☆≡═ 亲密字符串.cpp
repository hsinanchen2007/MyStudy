1. 统计字符串A，B中字符不匹配的下标。
2. 不匹配的下标个数不等于 0 或 2 时，不能由A得到B。
3. 不匹配的下标个数等于0时，A与B中字符完全相同，还需要A中有重复字符。
4. 不匹配的下标个数等于2时，判断交换两对字符后是否匹配。

```
class Solution {
public:
    bool buddyStrings(const string& a, const string& b) {
        if (a.size() != b.size()) return false;
        vector<int> index_of_mismatch;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i]) {
                index_of_mismatch.push_back(i);
                if (2 < index_of_mismatch.size()) return false;
            }
        if (index_of_mismatch.size() == 0) {
            return set<char>(a.begin(), a.end()).size() < a.size();
        } else if (index_of_mismatch.size() == 2) {
            return a[index_of_mismatch[0]] == b[index_of_mismatch[1]] &&
                   a[index_of_mismatch[1]] == b[index_of_mismatch[0]];
        }
        return false;
    }
};
```

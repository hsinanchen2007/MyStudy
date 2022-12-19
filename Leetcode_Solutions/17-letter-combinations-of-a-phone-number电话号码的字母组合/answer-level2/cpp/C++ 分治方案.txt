### 解题思路

分治来解决该问题。详细看代码！

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<vector<string>> vecStr;
        for (int i = 0; i < digits.length(); i++) {
            int temp = digits[i] - '2';
            vecStr.push_back(vecPhoneString[temp]);
        }

        return mergeString(vecStr, 0, vecStr.size() - 1);
    }

    vector<string> mergeString(vector<vector<string>>& vecStr, int left, int right)
    {
        if (left == right) {
            return vecStr[left];
        }

        vector<string> ret;
        if (left < right) {
            // 只有2个vector元素时，那么可以选择合并了
            if (right - left == 1) {
                ret = MergeTwoString(vecStr[left], vecStr[right]);
                return ret;
            }

            int middle = (right - left) / 2 + left;
            vector<string> v1 = mergeString(vecStr, left, middle);
            vector<string> v2 = mergeString(vecStr, middle + 1, right);
            ret = MergeTwoString(v1, v2);
        }

        return ret;
    }

    vector<string> MergeTwoString(vector<string>& v1, vector<string>& v2)
    {
        vector<string> ret;
        for (int i = 0; i < v1.size(); i++) {
            for (int j = 0; j < v2.size(); j++) {
                string temp = v1[i] + v2[j];
                ret.push_back(temp);
            }
        }
        
        return ret;
    }

private:
    vector<vector<string>> vecPhoneString = {{"a", "b", "c"}, {"d", "e", "f"}, {"g", "h", "i"},
                                             {"j", "k", "l"}, {"m", "n", "o"}, {"p", "q", "r", "s"},
                                             {"t", "u", "v"}, {"w", "x", "y", "z"}};
};
```
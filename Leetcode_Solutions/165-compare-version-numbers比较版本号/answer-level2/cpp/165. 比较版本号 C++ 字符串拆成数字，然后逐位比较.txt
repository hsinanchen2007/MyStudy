### 解题思路
字符串拆成数字，然后逐位比较

### 代码

```cpp
class Solution {
public:
    vector<int> GetVersionNums(string version)
    {
        stringstream strstream1;
        stringstream strstream2;
        vector<int> versionnums;
        strstream1 << version;
        string str;

        while (getline(strstream1, str, '.')) {
            int num = 0;
            strstream2 << str;
            strstream2 >> num;
            versionnums.push_back(num);
            strstream2.clear();
        }

        return versionnums;
    }

    int compareVersion(string version1, string version2)
    {
        vector<int> version1nums = GetVersionNums(version1);
        vector<int> version2nums = GetVersionNums(version2);
        int big = 1;
        int small = -1;
        int equal = 0;

        int minlength = min(version1nums.size(), version2nums.size());

        for (int i = 0; i < minlength; i++) {
            if (version1nums[i] > version2nums[i]) {
                return big;
            } else if (version1nums[i] < version2nums[i]) {
                return small;
            }
        }

        if (version1nums.size() == version2nums.size()) {
            return equal;
        }

        if (version1nums.size() < version2nums.size()) {
            for (int i = version1nums.size(); i < version2nums.size(); i++) {
                if (version2nums[i] != 0) {
                    return small;
                }
            }
            return equal;
        }

        if (version1nums.size() > version2nums.size()) {
            for (int i = version2nums.size(); i < version1nums.size(); i++) {
                if (version1nums[i] != 0) {
                    return big;
                }
            }

            return equal;
        }

        return big;
    }
};
```
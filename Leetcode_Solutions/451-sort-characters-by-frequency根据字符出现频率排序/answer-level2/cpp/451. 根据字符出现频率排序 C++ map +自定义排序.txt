### 解题思路
定义1个全局map 保存字符出现的顺序；然后用sort排序

### 代码

```cpp
unordered_map<char, int> countmap;
class Solution {
public:
    static bool myfun(char a, char b)
    {
        if (countmap[a] > countmap[b]) {
            return true;
        } else if (countmap[a] == countmap[b]) {
            if (a < b) {
                return true;
            }
        }

        return false;
    }

    string frequencySort(string s)
    {
        countmap.clear();
        for (auto c : s) {
            countmap[c]++;
        }

        sort(s.begin(), s.end(), myfun);
        return s;
    }
};
```
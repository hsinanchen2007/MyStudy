### 解题思路
此处撰写解题思路
字符串比较，题目的意思是字符串s1顺序是全排列，字符串s2中必须与s1是连续的相同字符时能找到，使用活动窗口、快慢指针。
### 代码

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        if (m > n) {
            return false;
        }

        vector<int> s1_map(26, 0);
        vector<int> s2_map(26, 0);
        for (int i = 0; i < m; i++) {
            s1_map[s1[i] - 'a']++;
        }
        //快慢指针
        int j = 0;
        for (int i = 0; i < n; i++) {
            s2_map[s2[i] - 'a']++;
            while (i - j + 1 > m) {
                s2_map[s2[j] - 'a']--;
                j++;
            }
            if (s1_map == s2_map) {
                return true;
            }
        }
        return false;
    }
};
```
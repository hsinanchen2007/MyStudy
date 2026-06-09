这个题思路比较单一， 遍历一遍数组，并统计每个字符的个数，我用的unordered_map，因为碰到字符计数的，第一感觉就想到了map，
 然后遍历一遍unordered_map，看第一个值为1的就是答案。返回坐标。
```cpp
class Solution {
public:
    int firstUniqChar(string s) {

        int len = s.size();
        int res = -1;

        unordered_map <int, int> m;

        for (int i=0; i<len; i++)
        {
            m[s[i]]++;

        }

        for (int i=0; i<len; i++)
        {
            if (m[s[i]] == 1)
            {
                res = i;
                break;
            }
        }

        return res;
    }
};
```
不要尝试暴力，会超时。

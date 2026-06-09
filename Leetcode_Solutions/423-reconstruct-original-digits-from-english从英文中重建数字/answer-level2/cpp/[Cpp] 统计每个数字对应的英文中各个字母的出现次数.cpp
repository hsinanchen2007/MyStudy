### 代码

```cpp
class Solution {
public:
    string originalDigits(string s) {
        map<char, int> map1;
        for (auto it : s) map1[it]++;

        map<int, int> map2;
        map2[0] = map1['z'];
        map2[2] = map1['w'];
        map2[4] = map1['u'];
        map2[6] = map1['x'];
        map2[8] = map1['g'];
        map2[1] = map1['o'] - map2[0] - map2[2] - map2[4];
        map2[3] = map1['r'] - map2[0] - map2[4];
        map2[5] = map1['f'] - map2[4];
        map2[7] = map1['s'] - map2[6];
        map2[9] = map1['i'] - map2[5] - map2[6] - map2[8];

        string res;
        for (auto& it : map2) {
            res.insert(res.end(), it.second, it.first + '0');
        }

        return res;
    }
};
```
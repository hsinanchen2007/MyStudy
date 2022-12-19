```cpp
class Solution {
public:
    vector<pair<char, char>> Two{ { '1','1' }, { '6','9' }, { '8','8' }, { '9','6' }, { '0','0' } };
    vector<string> findStrobogrammatic(int n) {
        return findStro(n, true);
    }

    vector<string> findStro(int n, bool outside) {
        if (!n)
            return { "" };
        else if (n == 1)
            return { "0","1","8" };
        else {
            vector<string> result;
            vector<string> tmp = findStro(n - 2, false);
            for (string& str : tmp)
                for (int i = 0; i < 5 - outside; ++i)
                    result.push_back(Two[i].first + str + Two[i].second);
            return result;
        }
    }
};
```

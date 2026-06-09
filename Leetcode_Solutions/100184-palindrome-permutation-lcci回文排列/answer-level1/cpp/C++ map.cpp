```
class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> m;
        for (auto i : s)
        {
            m[i]++;
        }
        int cnt = 0;
        for (auto i : m)
        {
            if (i.second & 1)
                cnt++;
        }
        return (cnt <= 1);
    }
};
```



用数组统计也是一个道理
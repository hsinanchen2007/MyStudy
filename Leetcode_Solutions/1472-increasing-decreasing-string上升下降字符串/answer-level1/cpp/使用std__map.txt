使用了std::map<char, int>，既是O(1)访问，还可以记录个数，也是排序好的
Complexity: O(n), Space: O(n)
while loop 里面第一个for使用了iterator遍历，第二个for使用了reverse_iterator反向遍历
``` C++
class Solution {
public:
    string sortString(string s) {
        if(s.size() <= 1) return s;
        std::map<char, int> m;
        for(auto x : s) ++m[x];
        std::string res;
        while(res.size() < s.size())
        {
            for(auto it = m.begin(); it != m.end(); ++it)
            {
                if(it->second > 0)
                {
                    res += it->first;
                    --it->second;
                }
            }
            for(auto rit = m.rbegin(); rit != m.rend(); ++rit)
            {
                if(rit->second > 0)
                {
                    res += rit->first;
                    --rit->second;
                }
            }
        }
        return res;
    }
};
```

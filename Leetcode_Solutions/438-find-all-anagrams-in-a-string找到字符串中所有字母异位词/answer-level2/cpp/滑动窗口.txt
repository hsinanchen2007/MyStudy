### 解题思路
这里的两个关键点：
1.如何判断字母异位词
（1）长度要相等
（2）子串中对应字母的个数一致，这里使用hash表进行存储计数
代码：
```
    bool isSame(unordered_map<char, int>& p, unordered_map<char, int>& s)
    {
        for(auto cm : p)
        {
            if(cm.second != s[cm.first])
            {
                return false;
            }
        }
        return true;
    }
```
2. 利用滑动窗口，不断遍历整个字符串，当r和l变化时，对应的字符计数也要变化


### 代码

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.empty()||p.empty()||s.size() < p.size())
        {
            return res;
        }

        int l = 0;
        int r = -1;

        std::unordered_map<char, int> c_map;
        std::unordered_map<char, int> c_temp;

        for(auto c : p)
        {
            c_map[c]++;
        }
 
        while(r+1 <s.size())
        {
            ++r;
            c_temp[s[r]]++;
            if(r-l+1 > p.size())
            {
                c_temp[s[l]]--;
                ++l;
            }
            if(r-l+1 == p.size() && isSame(c_map, c_temp))
            {
                res.push_back(l);
            }
            
        }
        return res;
    }

    bool isSame(unordered_map<char, int>& p, unordered_map<char, int>& s)
    {
        for(auto cm : p)
        {
            if(cm.second != s[cm.first])
            {
                return false;
            }
        }
        return true;
    }
};
```
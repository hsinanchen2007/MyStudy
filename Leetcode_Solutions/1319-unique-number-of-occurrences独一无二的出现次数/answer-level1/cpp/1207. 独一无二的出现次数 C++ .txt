### 解题思路


### 代码

```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        //统计各数字次数
        map<int, int> m;
        for(int i = 0; i < arr.size(); ++i)
        {
            ++m[arr.at(i)];
        }

        //次数查重
        set<int> s;
        for(auto iter = m.begin(); iter != m.end(); ++iter)
        {
            if(s.find(iter->second) != s.end())
                return false;
            
            s.insert(iter->second);
        }

        return true;
    }

    bool uniqueOccurrences(vector<int>& arr) {

        //统计次数
        map<int, int> m;
        for(int i = 0; i < arr.size(); ++i)
        {
            ++m[arr.at(i)];
        }

        //按次数排序 比较相邻次数是否相等
        vector<int> v;
        v.reserve(m.size());
        for(auto iter = m.begin(); iter != m.end(); ++iter)
        {
            v.push_back(iter->second);
        }

        sort(v.begin(), v.end());

        for(int i = 0; i < (int)v.size() - 1; ++i)
        {
            if(v.at(i + 1) == v.at(i))
                return false;
        }
        return true;
    }
};
```
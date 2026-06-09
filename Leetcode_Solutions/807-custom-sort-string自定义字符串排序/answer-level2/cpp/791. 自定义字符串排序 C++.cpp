### 解题思路

此题 与 1122. 数组的相对排序 类似

1、使用sort 自定义比较器

2、计数排序

### 代码

```cpp
class Solution {
public:
    //1
    string customSortString(string S, string T) {

        unordered_map<char, int> map;
        map.reserve(S.size() * 2);

        for (int i = 0; i < S.size(); ++i)
        {
            map[S.at(i)] = i;
        }

        sort(T.begin(), T.end(),
        [&](char l, char r) {
                
            auto iterl = map.find(l);
            auto iterr = map.find(r);

            if (iterl != map.end() && iterr != map.end())
            {
                return iterl->second < iterr->second;
            }
            else if(iterl != map.end())
            {
                return true;
            }
            else if (iterr != map.end())
            {
                return false;
            }
            else
            {
                return l < r;
            }
        });

        return T;
    }

    //2
    string customSortString(string S, string T) {

        string res(T.size(), '\0');

        vector<int> counts(128);
        for (int i = 0; i < T.size(); ++i)
        {
            ++counts[T.at(i)];
        }

        int k = 0;
        for (int i = 0; i < S.size(); ++i)
        {
            for (int j = 0; j < counts.at(S.at(i)); ++j)
            {
                res.at(k) = S.at(i);
                ++k;
            }

            counts.at(S.at(i)) = 0;
        }

        for (int i = 0; i < counts.size(); ++i)
        {
            for (int j = 0; j < counts.at(i); ++j)
            {
                res.at(k) = i;
                ++k;
            }
        }

        return res;
    }
};
```
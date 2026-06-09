### 解题思路
一种小思路，仅供参考（减少字符串比较的次数）
1、按照最后一个字符来进行归类。
2、归类以后，按照字符串的长短来排序。
3、判断每一个类别的字符串里面，短的字符串是否是长的字符串的结尾
### 代码

```cpp
bool compare_string(string& a, string& b)
{
    return a.size() > b.size();
}

bool string_end_with(string& a, string& b)
{
    int size_a = a.size();
    int size_b = b.size();
    for(int i = 1; i <= size_b; ++i)
    {
        if(a[size_a - i] != b[size_b - i])
        {
            return false;
        }
    }

    return true;
}

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) 
    {
        map<char, vector<string>> map_tmp;
        for(int i = 0; i < words.size(); ++i)
        {
            char c = words[i][words[i].size() - 1];
            if(map_tmp.find(c) != map_tmp.end())
            {
                map_tmp[c].push_back(words[i]);
            }
            else
            {
                vector<string> vct_tmp;
                vct_tmp.push_back(words[i]);
                map_tmp.insert(make_pair(c, vct_tmp));
            }
        }

        int index = 0;
        map<char, vector<string>>::iterator iter_map = map_tmp.begin();
        for(; map_tmp.end() != iter_map; ++iter_map)
        {
            sort(iter_map->second.begin(), iter_map->second.end(), compare_string);
            vector<string>& vct_tmp = iter_map->second;

            index += vct_tmp[0].size() + 1;
            for(int i = 1; i < vct_tmp.size(); ++i)
            {
                int j = 0;
                for(; j < i; ++j)
                {
                    if(string_end_with(vct_tmp[j], vct_tmp[i]))
                    {
                        break;
                    }
                }

                if(j >= i)
                {
                    index += vct_tmp[i].size() + 1;
                }
            }
        }

        return index;
    }
};
```
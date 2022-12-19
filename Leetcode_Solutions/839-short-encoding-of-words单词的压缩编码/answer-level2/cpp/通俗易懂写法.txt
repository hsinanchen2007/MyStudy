### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:

    static int cmp(const string &s1 , const string &s2) {
        return s1.size() > s2.size();
    }

    int minimumLengthEncoding(vector<string>& words) {
        string s;

        sort(words.begin() , words.end() , cmp);

        s.append(words[0] + "#");
        for (int i = 1; i < words.size(); i++) {
            int index_str = s.find(words[i]);
            int str_length = words[i].size();
            int index_tag = s.find("#" , index_str);

            if(index_tag - index_str == str_length) {
                continue;
            }

            s.append(words[i] + "#");
        }

        return s.size();
    }
};
```
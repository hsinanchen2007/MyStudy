![image.png](https://pic.leetcode-cn.com/8764822dc82309ea2ecba3eef1f626ba8d440c4c8d29a994d45c1f3b6565b149-image.png)

一不小心 

```
class Solution {
public:
    void int2str(const int &int_temp, string &string_temp)
    {
        stringstream stream;
        stream << int_temp;
        string_temp = stream.str();   //此处也可以用 stream>>string_temp
    }
    string compressString(string S)
    {
        if (S == "") {
            return "";
        }
        string tmp;
        vector<pair<char, int>> charCnt;
        char lastchar = S.at(0);
        int cnt = 0;
        printf("%d",S.length());
        for (size_t i = 0; i < S.length(); i++) {
            if (S.at(i) == lastchar) {
                cnt++;
            } else {
                charCnt.push_back(make_pair(lastchar, cnt));
                lastchar = S.at(i);
                cnt = 1;
            }
        }

        charCnt.push_back(make_pair(lastchar, cnt));

        if (charCnt.size() * 2 >= S.length()) {
            return S;
        }

        for (size_t i = 0; i < charCnt.size(); i++) {
            tmp += charCnt[i].first;
            string numstr;
            int2str(charCnt[i].second, numstr);
            tmp += numstr;
        }
        return tmp;
    }
};
```


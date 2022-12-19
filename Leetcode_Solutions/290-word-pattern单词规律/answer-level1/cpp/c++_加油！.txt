![单词规律.png](https://pic.leetcode-cn.com/d9bf35432afc0ba621231e4c1d440fecd8c2b9c5a90280369ef30e1616121049-%E5%8D%95%E8%AF%8D%E8%A7%84%E5%BE%8B.png)

方法1：

```
class Solution {
public:
    bool wordPattern(string pattern, string str) {
            string::size_type pos;
            vector<string> st;
            string p = " ";
            str += p;
            for (int i = 0; i < str.size(); i++){
                pos = str.find(p, i);
                if (pos < str.size()){
                    string s = str.substr(i, pos - i);
                    st.push_back(s);
                    i = pos + p.size() - 1;
                   }
            }
            //for (int i = 0; i < st.size(); i++)
                //cout << st[i] << '*';
            map<char, int> mp1;
            map<string, int> mp2;
            if (pattern.size() != st.size())
                return false;
            for (int i = 0; i < pattern.size(); i++){
                mp1[pattern[i]] = i;
                mp2[st[i]] = i;   
            }
            for (int i = 0; i < pattern.size(); i++){
                if (mp1[pattern[i]] != mp2[st[i]])
                    return false;
            }
            return true;
        }       
};
```


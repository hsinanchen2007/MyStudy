**C++实现split**
```cpp
class Solution {
public:
    vector<string> split(const string& s, const char* c)
    {
        vector<string> v;
        int len = s.size();

        char *p = new char[len + 1];
        strcpy(p, s.c_str());

        char* tok = strtok(p, c);
        while(tok){
            string tmp(tok);
            v.push_back(tmp);
            tok = strtok(NULL, c);
        }

        delete [] p;
        return v;
    }

    string reverseWords(string s) 
    {
        if(s == "")
            return s;
        string ret;
        vector<string> v = split(s, " ");
        for(auto& i : v){
            reverse(i.begin(), i.end());
            ret += i + " ";
        }
        ret.erase(ret.end() - 1);  //删掉最后的" "
        return ret;
    }
};
```
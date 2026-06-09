```
class Solution {
public:
    static vector<string> split2kv(const string & str, const char flag = ' ') 
    {
        vector<string> kv;
        istringstream iss(str);
        string key, value;
        getline(iss, key, flag);
        getline(iss, value);
        kv.push_back(key);
        kv.push_back(value);
        return kv;
    }
    
    static bool compare(string str1, string str2)
    {
        bool res = false;
        vector<string> kv1 = split2kv(str1), kv2 = split2kv(str2);
        bool isDigit1 = kv1[1][0] >= '0' && kv1[1][0] <= '9'; 
        bool isDigit2 = kv2[1][0] >= '0' && kv2[1][0] <= '9'; 
        if(!isDigit1 && !isDigit2) 
        {
            if(kv1[1] != kv2[1])
                return kv1[1] < kv2[1];
            else
                return kv1[0] < kv2[0];
        }
        else if(isDigit1 && isDigit2)
        {
            return false;   
        }
        else if(isDigit1 && !isDigit2)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
    vector<string> reorderLogFiles(vector<string> & logs) {
        stable_sort(logs.begin(), logs.end(), compare);
        return logs;
    }
};
```
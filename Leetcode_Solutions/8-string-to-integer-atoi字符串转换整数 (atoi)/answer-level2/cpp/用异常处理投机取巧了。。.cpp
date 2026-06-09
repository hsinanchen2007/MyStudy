```
class Solution {
public:
    int myAtoi(string str) {
        string numstr;
        int pos = 0, res;
        bool positive = true;
        while(str[pos] == ' ') ++pos;
        if(str[pos] == '+' || str[pos] == '-'){
            if(str[pos] == '-') positive = false;
            numstr.push_back(str[pos++]);
        }
        while(isdigit(str[pos])) numstr.push_back(str[pos++]);
        if(numstr.empty() || (numstr.size() == 1 && !isdigit(numstr[0]))) return 0;
        try{
            res = stoi(numstr);
        }
        catch(out_of_range){
            if(positive) return INT_MAX;
            else return INT_MIN;
        }
        return res;
    }
};
```

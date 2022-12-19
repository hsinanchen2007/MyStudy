```
class Solution {
public:
    long reminder,numerator,denominator;
    int cnt,sign=1;
    unordered_map<int,int> rec;
    string fractionToDecimal(int numerators, int denominators) {
        numerator = numerators;
        denominator = denominators;
        if(numerator==0) return "0";
        if(numerator<0) sign=-sign;
        if(denominator<0) sign=-sign;
        numerator = abs(numerator);denominator = abs(denominator);
        string n = (sign==-1?"-":"") + trans(numerator/denominator);
        reminder = numerator % denominator;
        if(!reminder) return n;
        n.push_back('.');
        string res;
        while(reminder) {//竖式模拟
            reminder *= 10;
            if(rec.count(reminder)) break;//余数若出现过即可判断出现循环节
            res.push_back(reminder/denominator+'0');
            rec[reminder] = cnt++;
            reminder %= denominator;
        }
        if(reminder) n += res.substr(0,rec[reminder]) + "(" + res.substr(rec[reminder]) + ")";
        else n += res;
        return n;
    }
    string trans(long n) {
        static stringstream ss;
        static string s;
        ss.clear();ss << n;ss >> s;
        return s;
    }
};
```

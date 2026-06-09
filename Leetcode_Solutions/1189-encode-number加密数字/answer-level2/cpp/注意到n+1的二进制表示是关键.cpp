0ms时间
```
class Solution {
public:
    string encode(int num) {
        string str;
        ++num;
        while(num>1){
            str.push_back(num%2+'0');
            num/=2;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
```

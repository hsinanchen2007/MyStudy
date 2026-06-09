依题意，罗马数字的特点是，从右往左算，如果当前符号是小于其右侧符号的，则总数值减去自身，否则相加。
```
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int bool_ ;
        int sum=mp[s[s.size()-1]];
        for(int i=s.size()-2;i>=0;i--){
            bool_=(mp[s[i]]>=mp[s[i+1]])?1:-1;
            sum+=bool_*mp[s[i]];
        }
        return sum;
    }
};
```
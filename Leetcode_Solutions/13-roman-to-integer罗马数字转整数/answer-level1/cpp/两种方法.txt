方法一
```
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string,int> mp={{"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900},{"I",1},{"V",5},{"X",10},{"L",50},{"C",100},{"D",500},{"M",1000}};
        int ans=0;
        for(int i=0;i<s.size();){
            string str1=s.substr(i,1);
            string str2=s.substr(i,2);
            i=mp.count(str2)?i+2:i+1;
            str2=mp.count(str2)?str2:str1;
            ans +=mp[str2];
        }
        return ans;
    }
};
```
方法二
```
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int len = s.size(), ans = 0;
        for(int i = 0; i < len; i ++){
            if(i == len - 1){
                ans += mp[s[i]];
                break;
            }
            if(mp[s[i]] < mp[s[i + 1]]){
                ans += mp[s[i + 1]] - mp[s[i]];
                i++;
            }
            else ans += mp[s[i]];
        }
        return ans;
    }
};
```
```
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int len = s.size(), ans = 0;
        for(int i = 0; i < len; i ++){
            if(mp[s[i]] < mp[s[i + 1]]) ans -= mp[s[i]];
            else ans += mp[s[i]];
        }
        return ans;
    }
};
```

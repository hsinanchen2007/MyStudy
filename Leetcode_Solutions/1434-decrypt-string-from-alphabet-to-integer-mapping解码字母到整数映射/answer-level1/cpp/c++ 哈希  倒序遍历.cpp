### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string freqAlphabets(string s) {
        vector<char> word = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        vector<string> trans = {"1","2","3","4","5","6","7","8","9","10#","11#","12#","13#","14#","15#","16#","17#","18#","19#","20#","21#","22#","23#","24#","25#","26#"};
        unordered_map<string,char> hash;
        for(int i = 0;i<trans.size();i++){
            hash[trans[i]] = word[i];
        }
        string res = "";
        for(int i = s.size()-1;i>=0;){
            if(s[i] != '#'){
                string ch(1,s[i]);
                res = hash[ch]+res;
                i--;
            }
            else{
                string temp = s.substr(i-2,3);
                res = hash[temp]+res;
                i = i-3;
            }
        }
        return res;

    }
};
```
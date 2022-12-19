### 解题思路
此处撰写解题思路
h函数主要分为：split（将字符串分为两部分），valid和dotValid(分别检测不带小数点与带小数点的数是否合法)，addDot（将小数点插入数中）
### 代码

```cpp
class Solution {
public:
    vector<string> res;
    bool dotValid(string s){
        if(s.back() == '0')
                return false;
        int mark=0;
        for(int i =0;i<s.size();i++){
            if(s[i] == '.'){
                mark = i;
                break;
            }
        }
        if(mark > 1 && s[0] == '0')
            return false;
        return true;
    }
    bool valid(string s){
            if(s[0] != '0' ||s.size() ==1)
                return true;
            return false;
        }
    
    vector<string> addDot(string s){
        vector<string> geter;
        for(int i = 1;i<s.size();i++){
            string test = s.substr(0,i)+'.'+s.substr(i);
            if(dotValid(test)){
                geter.push_back(test);
            }
            
        }
        return geter;
    }
    void split(string S,int n){
        string pre = "",back = "";
        for(int i = 0;i < n;i++){
            pre += S[i];
        }
        for(int i = n;i < S.size();i++){
            back += S[i];
        }
        vector<string> dot1 = addDot(pre);
        if(valid(pre))
            dot1.push_back(pre);
        vector<string> dot2 = addDot(back);
        if(valid(back))
            dot2.push_back(back);
        for(auto pice1:dot1){
            for(auto pice2:dot2){
                res.push_back("(" + pice1 + ", " + pice2 + ")");
            }
        }
    }
    vector<string> ambiguousCoordinates(string S) {
        string s = S.substr(1, S.size() - 2);
        for(int i = 1; i < s.size(); i++){
            split(s,i);
        }
        return res;
    }
};
```
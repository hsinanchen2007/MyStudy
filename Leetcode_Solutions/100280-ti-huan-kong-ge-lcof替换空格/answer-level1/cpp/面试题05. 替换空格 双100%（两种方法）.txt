方法一
```
class Solution {
public:
    string replaceSpace(string s) {
        string res;   
        for(auto c : s){   
            if(c == ' ') res +="%20";
            else res += c;
        }
        return res;
    }
};
```
方法二
```
class Solution {
public:
    string replaceSpace(string s) {
    int pos; //string::size_type pos;
    while((pos=s.find(' '))!=s.npos) s.replace(pos,1,"%20");//替换       pos=s.find(" ")
    return s; 
    }
};
```


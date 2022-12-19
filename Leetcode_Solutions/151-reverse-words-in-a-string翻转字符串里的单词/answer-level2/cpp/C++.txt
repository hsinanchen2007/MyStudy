### 解题思路
这题我好久之前就做过了，具体的思路就是删增，用头插法增
### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())return "";
        string tem;
        list<string>ls;
       s.append(" ");//具有战略意义的空格
        for(auto val:s){
            if(!isspace(val)){
                tem+=val;
            }
            else if(!tem.empty()){
                ls.insert(ls.begin(),tem);
                tem.clear();
            }
        }
        auto it=ls.begin();
        tem.clear();
        int num=0;
        if(ls.empty())return "";
        while(it!=ls.end()){
            if(num==ls.size()-1){break;}
            ++num;
            tem+=*it++;
            tem+=" ";
        }
        tem+=*it;
        return tem;
    }
};
```
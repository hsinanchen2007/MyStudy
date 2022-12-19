创建一个map记录字符和该字符出现次数
用出现的次数作为“键”，出现的字符作为“值”再创建一个map
遍历第二个map（因为map会根据键值来进行字典排序），建立目标字符串


```
class Solution {
public:
    string frequencySort(string s) {
        string ret("");
        map<char,int> tmpa;
        multimap<int,char> tmpb;
        for(char c:s){
            if(tmpa.count(c)==0){
                tmpa.insert(map<char,int>::value_type(c,1));
                continue;
            }              
            tmpa[c]++;
        }
        for(auto it=tmpa.begin();it!=tmpa.end();it++){
            if(tmpb.count(it->first)==0)
                tmpb.insert(multimap<int,char>::value_type(it->second,it->first));
        }
        for(auto it=tmpb.begin();it!=tmpb.end();it++){
            ret.insert(0,it->first,it->second);
        }
        return ret;
    }
};
```

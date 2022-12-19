map的键值映射是可以多对一的映射，但是题目的要求是希望得到字符到字符的唯一映射关系
思路就是用一个字符串的字符来做“键”，另一个字符串的字符来做“值”，但是要保证不同的键必须对应不同的值：
```
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s == t)
            return true;
        map<char,char> res;
        string tmp("");
        for(int i=0;i<s.size();i++){
            if(res.count(s[i])==0){
                res.insert(map<char,char>::value_type(s[i],t[i]));
                /*用新键值对的“值”构造一个字符串，如果这个字符串出现了重复的字符，那么就说明map中插入了多对一的映射关系，返回false*/
                tmp.append(1,t[i]);
                if((tmp.find(t[i])!=tmp.npos)&&(tmp.find(t[i])!=tmp.size()-1))
                    return false;
                continue;
            }
            if(res[s[i]]!=t[i])
                return false;
        }
        
        return true;
    }
};
```

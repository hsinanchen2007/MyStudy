有题目可知，如果要返回true，则需要同时满足一下三点
1. pattern的length与str分割(分隔符是空格)出来的字符串的个数要相等
2. 由str分割出来的第i个字符串strtemp;strtemp如果已经出现，则其哈希表中所存储的字符x，必然与pattern[i]一致
3. 由str分割出来的第i个字符串strtemp;strtemp如果没有出现，则pattern[i]必然没有出现在哈希表中
```
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<string,char> Map;
        vector<bool> used(128,0); //记录pattern中的字符是否出现过
        str.push_back(' '); //方便分割
        int i=0, j=0;
        string strtemp;
        map<string,char>::iterator iter;
        for(; i<pattern.length() && j<str.length(); i++,j++){
            while(str[j]!=' ') strtemp.push_back(str[j++]);
            iter = Map.find(strtemp);
            if(iter == Map.end()){
                if(used[pattern[i]] == true) return false;
                Map.insert(pair<string,char>(strtemp,pattern[i]));
                used[pattern[i]] = true;
            }else{
                if(iter->second != pattern[i]) return false;
            }
            strtemp = "";
        }
        return i==pattern.length() && j==str.length();
    }
};
```

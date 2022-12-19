
```
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> map1;
        vector<char> vec;
        for(int i=0;i<s.size();i++){
            if(!map1[s[i]]) vec.push_back(s[i]);//在每个字母第一次出现时存入vec，用于遍历第一个次数为1的数
            map1[s[i]]+=1;//统计每个字符出现的次数
        }
        for(int i=0;i<vec.size();i++) if(map1[vec[i]]==1) return vec[i];//若次数为1，则输出
        return ' ';//若没有次数为1，则输出空格‘ ’ 
    }
};
```

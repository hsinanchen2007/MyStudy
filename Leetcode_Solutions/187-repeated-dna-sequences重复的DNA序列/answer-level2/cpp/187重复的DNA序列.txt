```
class Solution {
public:
    //显然是个哈希表的问题，先把所有子串插入到哈希表中，然后判断次数
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> hash;//key是字符串,value是出现的次数

        vector<string> res;
        for(int i=0;i+10<=s.size();i++)
        {
            string str=s.substr(i,10);
            if(++hash[str]==2) res.push_back(str);//最开始出现的时候是hash[str]++,相当于，hash[str]=1;第二次出现就等于2了
        }
        return res;
    }
};
```

1. 此题可以看做为n位数字，可以表示多少位数；
2. 比如 n = 3 则 011b,如果某一位代表1，则表示保留改为的字符，某一位为0，则表示该位转换为数字。主要涉及到连续的数字即连续的0进行合并即可。
3. 总共有n^2中不同的字符串。

```
class Solution {
public:
   string bmToString(int  mask,string & word){
        string ans;
        int idx = 0;
        while(idx < word.size()){
            int last = idx;
            while(idx < word.size() && ((mask&(1<<idx))>>idx)){
                idx++;
            }   
            if(last != idx){
                ans += to_string(idx-last);
            }else{
                ans.push_back(word[idx]);
                idx++;
            }
        }
        return ans;
   }
   vector<string> generateAbbreviations(string word) {
        int n = word.size();
        int mask = 1<<n;  
        vector<string> ans;
        for(int i = 0;i < mask; ++i){
            ans.push_back(bmToString(i,word));
        }    
        return ans;
    }
};
```
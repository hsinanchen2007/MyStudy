```
class Solution {
public:
    bool isSubstr(string& s, string& d){
        int si = 0;
        int sj = s.size() - 1;
        int di = 0;
        int dj = d.size() - 1;
        while(si <= sj && di <= dj){
            if(s[si] == d[di]){
                si++;
                di++;
            }else{
                si++;
            }
            if(s[sj] == d[dj]){
                sj--;
                dj--;
            }else{
                sj--;
            }
        }
        if(di > dj){
            return true;
        }
        return false;
    }
    string findLongestWord(string s, vector<string>& d) {
        string reStr  = "";
        for (auto it : d)
        {
	        if(isSubstr(s,it)){
                int reStrSize = reStr.size();
                int itSize = it.size();
                if(reStr == "" || reStrSize < itSize
                 || (reStrSize == itSize && reStr > it)){
                    reStr = it;
                    continue;
                }
            }
        }
        return reStr;
    }
};
```

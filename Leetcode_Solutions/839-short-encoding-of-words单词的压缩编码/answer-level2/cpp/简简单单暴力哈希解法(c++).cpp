暴力哈希解法时间复杂度：O(n*length)约等于O(n):
把所有词的长度加起来，把后缀都用哈希表存下来，然后判断遇到过这个词是某个词的后缀的话，就该后缀长度减掉。
```
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string,unsigned int>mp;
        int len=0;
        for(string s:words){
            len+=(s.size()+1);
            for(int i=0;i<s.size();i++){              
                string tmp=s.substr(i);
                if(mp[tmp]==0){
                    if(i==0) mp[tmp]=2;
                    else mp[tmp]=1;
                }
                else{
                    if(i==0||mp[tmp]==2)
                    {
                        mp[tmp]=1;
                        len-=(tmp.size()+1);
                    }
                }
            }
        }
        return len;
    }
};
```

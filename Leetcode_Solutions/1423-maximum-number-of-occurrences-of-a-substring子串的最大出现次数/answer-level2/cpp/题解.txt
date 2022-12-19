首先可以不用管maxsize，假如说长度最长的子串出现了5次那么把它截掉一些它的字串肯定也同样出现在这些位置；
所以说只要扫长度为minsize，用map统计出现的次数，最后取个最大的就ok了。
### 代码

```cpp
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        map<string,int> mp;
        for(int i=0;i<=s.size()-minSize;i++){
            unordered_map<char,int> cnt;
            int cnt1=0;
            string temp=s.substr(i,minSize);
            for(int i=0;i<minSize;i++){
                if(!cnt[temp[i]]){
                    cnt[temp[i]]++;
                    cnt1++;
                }
            }
            if(cnt1<=maxLetters){
                mp[temp]++;
            }
        }
        int ans=0;
        for(auto item:mp){
            ans=max(ans,item.second);
        }
        return ans;
    }
};
```
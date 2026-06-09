### 解题思路
要想 如果一个大于minsize的子串满足条件，那一个等于minsize的子串一定也满足。
因此我们直接去检查minsize的子串就可以了。

### 代码

```cpp
class Solution {
public:
    map<string,int> mp;
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int len = s.size();
        for(int i=0;i<=len-minSize;i++){
            int count[26] = {0};
            string subs = s.substr(i,minSize);
            for(auto c:subs) count[c-'a']++;
            int keynums = 0;
            for(auto c:count) if(c>0) keynums++;
            if(keynums<=maxLetters){
                if(mp.find(subs)!=mp.end()) mp[subs]++;
                else mp[subs] = 1;
            }
        }
        int res=0;
        for(auto it:mp){
            res = res<(it.second)?it.second:res;
        }
        return res;
    }
};
```
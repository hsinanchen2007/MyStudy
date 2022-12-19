```
class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> v(26,0);
        for(auto a:s){
            ++v[a-'a'];
        }
        map<char,bool> m;
        bool flag=false;
        for(int i=0;i<26;++i){
            if(v[i]<k&&v[i]>0){
                m[i+'a']=true;
                flag=true;

            }
        }
        if(!flag){
            return s.size();
        }
        int front=0;
        int ans=INT_MIN;
        for(int i=0;i<s.size();++i){
            if(m[s[i]]){
                ans=max(ans,longestSubstring(s.substr(front,i-front),k));
                front=i+1;
            }
            
        }
        ans=max(ans,longestSubstring(s.substr(front),k));
        return ans;
        
    }
};
```

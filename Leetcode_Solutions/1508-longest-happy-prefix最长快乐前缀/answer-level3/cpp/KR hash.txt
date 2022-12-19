```c++
const int Base = 37;
const int Mod = 1e9+7;
class Solution {
public:
    bool check(string & s,int l){
        int d = s.size()-l;
        for(int i = 0; i < l; ++i){
            if(s[i] != s[i+d]) return false;
        }
        return true;
    }

    string longestPrefix(string s) {
        int n = s.size();
        vector<long long> h(n+1,0);
        vector<long long> p(n+1,1);
        string res;
        
        for(int i = 0; i < n; ++i){
            h[i+1] = (h[i]*Base + s[i])%Mod;
        }
        for(int i = 0; i < n; ++i){
            p[i+1] = (p[i]*Base)%Mod;
        }
        auto get = [&](int x,int y){
            return (h[y] - h[x-1]*p[y-x+1]%Mod + Mod)%Mod;
        };
        for(int i = 2; i <= n; ++i){
            if(get(i,n) == h[n-i+1]&&check(s,n-i+1)){
                return s.substr(0,n-i+1);
            }
        }
        
        return res;
    }
};
```
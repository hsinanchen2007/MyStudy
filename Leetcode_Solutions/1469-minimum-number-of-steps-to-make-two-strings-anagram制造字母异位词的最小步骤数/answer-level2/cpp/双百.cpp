### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minSteps(string s, string t) {
        map<int,int> a;
        map<int,int> b;
        for(int i=0;i<s.length();i++){
            a[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            b[t[i]-'a']++;
        }
        int ans=0;
        for(auto it=a.begin();it!=a.end();it++){
            int d=it->first;
            if(it->second>b[d]){
                ans+=it->second-b[d];
            }
        }
        return ans;
    }
};
```
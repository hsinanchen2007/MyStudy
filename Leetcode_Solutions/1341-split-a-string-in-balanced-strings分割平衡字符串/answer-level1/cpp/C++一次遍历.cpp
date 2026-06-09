这道题简单得很，没什么好说的
```
class Solution {
public:
    int balancedStringSplit(string s) {
        int flag=0;
        int sum=0;
        for (int i=0;i<s.size();++i){
            if (s[i]=='L') flag+=1;
            else flag-=1;
            if(flag==0) ++sum;
        }
        return sum;
    }
};
```

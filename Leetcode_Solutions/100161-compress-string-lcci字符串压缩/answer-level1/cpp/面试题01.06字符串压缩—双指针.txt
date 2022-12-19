字符串压缩——双指针
```
class Solution {
public:
    string compressString(string S) {
        string res="";
        int cnt=1,i=0,j=1;
        while(j<=S.size()){
            if(cnt==1) res +=S[i];
            if(S[j]==S[i]) cnt++;
            else{
                i=j;
                res +=to_string(cnt);
                cnt=1;
            }
            j++;
        }
        return res.size()<S.size()?res:S;
    }
};
```
```
class Solution {
public:
    string compressString(string S) {
        string res="";
        int i=0,j=0;
        while(j<S.size()){
            while(S[i]==S[j]) j++;
            res +=S[i]+to_string(j-i);         
            i=j;
        }
        return res.size()<S.size()?res:S;
    }
};
```


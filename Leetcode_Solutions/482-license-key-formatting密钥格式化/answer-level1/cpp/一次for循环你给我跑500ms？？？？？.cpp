```
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int step=0,count=0;
        for(int i=S.length()-1;i-step>=0;i--)
        {
            if(S[i-step]=='-')
            {
                step++;
                i++;
                continue;
            }
            if(S[i-step]>=97)
                S[i]=S[i-step]-32;
            else
                S[i]=S[i-step];
            count++;
            if(count==K&&i-1>=0&&i-step!=0)
            {
                if(step>0){
                    i--;
                    S[i]='-';
                    step--;
                    count=0;
                }else{
                    S = S.insert(i,1,'-');
                    count=0;
                }
            }
        }
        if(step>=S.length())
            return "";
        if(S[step]=='-')
            step++;
        S=S.substr(step);
        return S;
    }
};
```

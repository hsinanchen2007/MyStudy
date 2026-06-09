```
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int len1 = J.length();
        int len2 = S.length();
        int counter = 0;
        char stone[52]={};
        for(int i=0;i<len2;i++){
            if(S[i] >='A' && S[i]<='Z')
                stone[S[i]-'A']++;
            else
                stone[S[i]-'A'-6]++;
        }
        for(int j = 0;j<len1;j++){
            if(J[j]>='A' && J[j]<='Z')
                counter = counter+stone[J[j]-'A'];
            else
                counter = counter + stone[J[j]-'A'-6];
        }
        return counter;
        
    }
};
```

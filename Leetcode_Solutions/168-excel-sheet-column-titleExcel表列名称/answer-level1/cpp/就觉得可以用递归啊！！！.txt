```
class Solution {
public:
    string convertToTitle(int n) {
        long N = n;
        map<long,string> TMap;
        if (n <= 0) return "";
        for(long i = 0; i<26; i++)
        {
            TMap[i] = 'A'+i;
        }
        N--;
        if(N < 26) 
        {
            return TMap[N];
        }
        else
        {
            string re = TMap[N%26];
            return convertToTitle(N/26) + re;
        }
    }
};
```
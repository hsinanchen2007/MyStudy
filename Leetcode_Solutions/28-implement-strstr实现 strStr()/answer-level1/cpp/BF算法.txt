```
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack == needle) return 0;
        int M = haystack.size();
        int N = needle.size();
        if (N == 0) return 0;
        if(N > M) return -1;

        for(int i = 0; i < M-N + 1;i++){
            int j;
            for(j=0;j<N;j++){
                if(haystack[i+j] != needle[j]) break;
            }
            if( j == N) return i;
        }
        return -1;
    }
};
```

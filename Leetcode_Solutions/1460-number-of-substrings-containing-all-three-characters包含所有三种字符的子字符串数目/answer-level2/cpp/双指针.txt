```
class Solution {
public:
    int bucket[4];
    bool isValid(){
        if (bucket[0] != 0 && bucket[1] != 0 &&  bucket[2] !=0) return true;
        else return false;
    }
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        bucket[0] = 0;
        bucket[1] = 0;
        bucket[2] = 0;
        for (int i = 0, j = 0; i < n; i ++ ) 
        {   
            while (!isValid() && j != n)
            {
                bucket[s[j]-'a']++;
                j ++ ;
            }
            if (isValid()) cnt += n - j + 1;
            bucket[s[i]-'a']--;
        }
        return cnt;
    }
};
```
```
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s=to_string(N);
        int p=0;
        for(int i=s.length()-1;i>=1;i--)
        {
            if(s[i]<s[i-1])
            {
                p=i;
                s[i-1]--;  
                while(p<s.length())
                {
                    s[p++]='9';
                }
            }
        }
        return stoi(s);
    }
};




```

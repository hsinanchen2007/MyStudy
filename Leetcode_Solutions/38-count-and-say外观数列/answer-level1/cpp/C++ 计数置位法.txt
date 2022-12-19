```
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        if(n==1) return res;
        int round = n-1;
        while(round--)
        {
            string now = "";
            int cnt = 1;
            for(int i=0; i<res.length(); i++)
            {
                if(i+1 < res.length() && res[i] != res[i+1])
                {
                    now += ( to_string(cnt) + res.substr(i, 1) );
                    cnt = 1;
                }
                else if(i+1 >= res.length()) 
                    now += ( to_string(cnt) + res.substr(i, 1) );
                else cnt++;
            }
            res = now;
        }
        return res;
    }
};
```

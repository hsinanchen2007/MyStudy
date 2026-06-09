```
class Solution {
public:
    string countAndSay(int n) {
        string temp = "";
        string s = "11";
        int count = 1; 
        
        if(n==1) return "1";

        for(int j=2; j<n; j++)
        {
            temp = "";
            for(int i=0; i<s.size(); i++)
            {
                if(s[i] == s[i+1] && i<s.size()-1)
                {
                    count++;
                }
                else
                {
                    temp += to_string(count) + s[i];
                    count = 1;
                }
            }
            s = temp;
        }
        return s;
    }
};
```

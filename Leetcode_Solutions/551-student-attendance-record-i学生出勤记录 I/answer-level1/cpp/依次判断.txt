```
class Solution {
public:
    bool checkRecord(string s) {
        int late = 0;
        int absent = 0;
        for(char c:s)
        {
            if(c == 'L')
            {
                late++;                
            }
            else
            {
                if(c == 'A')
                {
                    absent++;
                }
                if(late<=2)
                    late = 0;
            }
            if(late>2 || absent>1)
                return false;
        }
        return true;
    }
};
```

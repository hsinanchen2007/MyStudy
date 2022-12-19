```
class Solution {
public:
    string toHex(int num) {
        unsigned int i = num;
        string s;
        if(num  == 0)
        {
            return "0";
        }
        while(i>0)
        {
            int m = 0;
            char c;
            m = i % 16;
            c = m>9 ? (m-10+'a') : (m+'0');
            i /= 16;
            s.insert(s.begin(), c);
        }
        return s;
    }
};
```

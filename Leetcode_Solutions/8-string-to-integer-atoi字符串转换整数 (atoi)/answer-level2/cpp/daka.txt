```
class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;
        //去除空格
        long long len=str.size();
        int idx=0;
        
        while(idx<len)
        {
            if(str[idx]!=' ')
                break;
            idx++;
        }
        if(idx==len) return 0;

        //sign
        int sign=1;
        if (str[idx] == '+') {
            idx++;
        } else if (str[idx] == '-') {
            sign = -1;
            idx++;
        }

        int res=0;
        while(idx<len)
        {
            char c=str[idx];
            if(c<'0'||c>'9') break;

            if(res>INT_MAX/10||(res==INT_MAX/10&&(c-'0')>INT_MAX%10)) return INT_MAX;
            if(res<INT_MIN/10||(res==INT_MIN/10&&(c-'0')>-(INT_MIN%10))) return INT_MIN;

            res=res*10+sign*(c-'0');
            idx++;
        }
        return res;
    }
};
```

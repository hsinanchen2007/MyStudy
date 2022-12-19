### 解题思路
此处撰写解题思路

### 代码

```cpp
class Operations {
public:
    Operations() {

    }
    int minus(int a, int b) {
        return a+(-b);
    }
    
    int multiply(long a, long b) {
    long result=0;
    int zerobits = 0;
    bool isPos;
    if ((a > 0 && b > 0) || (a < 0 && b < 0))
        isPos = true;
    else
        isPos = false;
    a = abs(a);
    b = abs(b);
    string b_str = to_string(b);
    reverse(b_str.begin(), b_str.end());
    const char* c_rbstr = b_str.c_str();
    for (int i = 0; i < b_str.length(); ++i) {
        int n = c_rbstr[i] - '0';
        long cur = 0;
        for (int j = 0; j < n; ++j)
            cur += a;
        string str_cur = to_string(cur);
        for (int p = 0; p < zerobits; ++p)
            str_cur += "0";

        cur = stol(str_cur);
        ++zerobits;
        result += cur;

    }
    if (isPos)
        return result;
    else
        return -result;
    }
    
    int divide(long long a, long long b) {
        bool isPos;
        if((a>0&&b>0)||(a<0&&b<0))
            isPos = true;
        else
            isPos = false;
        a=abs(a);
        b=abs(b);
        if(a<b)
            return 0;
        long long cur=0,result=0;
        const char *a_str;
        string t_str=to_string(a);
        a_str = t_str.c_str();
        for(int i=0;i<strlen(a_str);++i){
            long long tmp = a_str[i]-'0';         
            cur = multiply(10,cur)+tmp;
            long long cnt=0;
            while(cur>=b){
                cur  += (-b);
                ++cnt;
            }
            result = long(multiply(10,result))+cnt;
        }
        if(isPos)
        return result;
        else
        return -result;
    }
};

/**
 * Your Operations object will be instantiated and called as such:
 * Operations* obj = new Operations();
 * int param_1 = obj->minus(a,b);
 * int param_2 = obj->multiply(a,b);
 * int param_3 = obj->divide(a,b);
 */
```
这里提供一个看起来比较简明的递归解法，欢迎指正

```
class Solution {
public:
    string decodeString(string s) {
        istringstream iss(s);
        return helper(iss);
    }
    string helper(istringstream& iss){
        string res;
        char ch;
        int k = 0;
        while(iss>>ch){
            if(ch >= '0' && ch <= '9'){
                k = k*10 + ch - '0';
            }else if(ch == '['){
                string tmp = helper(iss);
                while(k){
                    res += tmp;
                    --k;
                }
            }else if(ch == ']'){
                return res;
            }else{
                res += ch;
            }
        }
        return res;
    }
};
```

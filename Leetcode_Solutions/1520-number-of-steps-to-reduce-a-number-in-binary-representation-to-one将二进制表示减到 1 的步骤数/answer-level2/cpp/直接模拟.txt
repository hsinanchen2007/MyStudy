1. 如果为偶数，则去掉最后一位。
2. 如果为奇数，则进行加1模拟。
```c++
class Solution {
public:
    string increment(string &s){
        int carry = 1;
        for(int i = s.size()-1; i >=0 ; --i){
            if(s[i] == '1' && carry == 1){
                s[i] = '0';
                carry = 1;
            }else{
                s[i] = s[i] + carry;
                carry = 0;
                break;
            }
        }
        return carry == 1?('1'+ s):(s);
    }
    
    string decrement(string & s){
        return s.substr(0,s.size()-1);
    }
    
    int numSteps(string s) {
        int res = 0;
        while(s != "1"){
            res++;
            if(s.back() == '1') s = increment(s);
            else s = decrement(s);
        }
        return res;
    }
};
```
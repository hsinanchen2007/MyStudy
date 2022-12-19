```
class Solution {
public:
    bool isNumber(string s) {
        if(s.empty()) return false;
        bool e=0,dot=0,num=0; //"e",".",数字三个标识符
        int lo = 0, hi = s.size()-1;
        while(lo<=hi && s[lo] == ' ') lo++; //将头部的空格略过
        while(hi>=lo && s[hi] == ' ') hi--; //将尾部的空格略过
        if(hi<lo) return false; //遍历完则s为空，返回false
        lo += (s[lo] == '+' || s[lo] == '-'); //若存在符号项'+'或'-'，则略过
        for(int i = lo; i<=hi; i++){ //对中间非空的字符串进行遍历
            if(s[i]>='0' && s[i]<='9'){ //case 1：数字
                num = 1; //将num置1，表示存在数字
            }
            else if(s[i] == '.'){ //case 2：小数点
                if(dot || e) return false; //若已经存在小数点或e，返回false
                dot = 1; //将dot置1，表示存在小数点
            }
            //case 3：e，此处没有包含'E'，可自行测试，emmm所以题目描述很迷
            else if(s[i] == 'e'){
                //若已经存在e，e前或后无数字，返回false
                if(e || !num || i ==hi) return false;
                if(s[i+1] == '+' || s[i+1] =='-') i++; //跳过e后符号项
                e = 1; num = 0; //将e置1，表示存在e，同时e后必须有数字，num置0
            }
            else return false; //其余情况均为false
        }
        return num;
    }
};
```


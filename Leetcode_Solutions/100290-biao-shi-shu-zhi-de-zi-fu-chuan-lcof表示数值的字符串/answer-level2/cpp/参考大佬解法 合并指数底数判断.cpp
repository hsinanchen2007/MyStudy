```
/* 判断是否为合法数字
 * 1.去除前后空格
 * 2. 按e所在位置划分 底数和指数（如果没有e就不用判断指数） 分别判断指数和底数是否合法
 * 3. 指数只能为带符号的整数  底数为带符号的小数
 *
 * */
class Solution {
public:
    bool isNumber(string s) {
        int i=0, j=s.length()-1;
        while(i<s.size() && s[i] == ' ') i++;
        while(j> 0 && s[j] == ' ') j--;
        if(i > j) return false;
        s = s.substr(i, j-i+1);
        int e_pos = -1;
        for(int i=0; i<s.size();i++){
            if(s[i] == 'e' || s[i] == 'E'){
                e_pos = i;
                break;
            }
        }
        if(e_pos == -1) return check(s);
        else return check(s.substr(0, e_pos)) && check(s.substr(e_pos+1), false);
    }
    bool check(string s, bool withPoint=true){
       bool ret = false;
       int dotNum = 0;
       for(int i=0; i<s.size();i++){
           if(s[i] == '+' || s[i] == '-'){
               if(i != 0)   return false;
           } 
           else if(s[i] == '.'){
               if(withPoint){
                   if(dotNum > 0) return false;
                   else dotNum++;
               }
               else return false;
           }
           else if(s[i] < '0' || s[i] > '9') return false;
           else ret = true; // 保证至少有一个数字
       }
       return ret;
    }
};
```

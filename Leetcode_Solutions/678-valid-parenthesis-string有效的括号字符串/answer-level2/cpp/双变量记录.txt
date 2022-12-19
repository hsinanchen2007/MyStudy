
使用l、h两个变量记录两种不同的状态
l 记录*为右括号的状态下，左括号到达当前位置剩余的数量
h 记录*不为右括号的状态下，左括号和*到达当前位置剩余的总数量
其中退出状态也有两种：
1、*为右括号时，左括号有剩余，此时l>0
2、*为左括号时，右括号有剩余，此时h<0

class Solution {
public:
    bool checkValidString(string s) {
        int len = s.size();
        int l,h;
        l = h = 0;
        for(int i = 0; i < len; i ++){
            if(s[i] == '('){
                l ++;
                h ++;
            }
            else{
                if(l) l--;
                if(s[i] == ')'){
                    h --;
                }
                else {
                    h ++;
                }
            }
            if(h < 0) return false;
        }
        return l == 0;
    }
};
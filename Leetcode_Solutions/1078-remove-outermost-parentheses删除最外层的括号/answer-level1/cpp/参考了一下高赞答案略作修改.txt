也无所谓跳过左括号，计量单位一个就可以。当num大于1全部存入字符串中，如果num为1，判断是否是右括号，右括号进左括号则跳过

class Solution {
public:
    string removeOuterParentheses(string S) {
        int num=0;
        string A;
        for(int i=0;i<S.size();i++){
            int a=S[i];
            if(a=='(')num++;  
            else num--;
            if(num>1||(num==1&&a==')'))A.push_back(a);
        }
        
        return A;
    }
};


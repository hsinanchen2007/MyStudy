执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户 内存消耗 :9 MB, 在所有 C++ 提交中击败了65.88%的用户

```
class Solution {
public:
    string removeOuterParentheses(string S) {
        int num=0;
        string result="";
        int start=1,end=0;
        for(int i=0;i<S.length();i++){
            if(S[i]=='(')
                num++;
            else
                num--;
            if(num==0){
                end=i;
                result+=S.substr(start,end-start);
                start=end+2;
            }
        }
        return result;
    }
};

```

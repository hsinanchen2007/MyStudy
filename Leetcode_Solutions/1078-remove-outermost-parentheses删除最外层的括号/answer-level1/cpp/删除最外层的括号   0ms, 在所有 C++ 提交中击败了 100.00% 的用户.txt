```
class Solution {
public:
    string removeOuterParentheses(string S) {
        string res,tmp;;
        int num=0;
        for(char c:S){
            if(c=='('&&num==0){
                num++;
                continue;
            }
            if(c=='('){
                num++;
                tmp +="(";
            } 
            if(c==')'){
                num--;
                if(num==0){
                    res +=tmp;
                    tmp.clear();
                    continue; 
                } 
                tmp +=")";
            } 
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/2b010e1049aff11717429ebcb5eff2b8f3de2e6b72a6e4aa35a73d60bdeebb5d-image.png)

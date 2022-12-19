关键是要分清题目中的几种表达式；
- 表达式为't',直接返回true;
- 表达式为'f',直接返回false;
- 表达式为'!',直接返回!后面的表达式的取反;
- 表达式为'|',直接对|后面的表达式子项求或;
- 表达式为'&',直接对|后面的表达式子项求与;
- 表达式为'(',直接对其进行脱掉()操作

```
class Solution {
public:
    /*split expression by ','*/
    vector<bool> split(const string expression){
        vector<bool> ans;
        int n = expression.size();
        int count = 0;
        int start = 0;
        
        for(int i = 0;i < expression.size(); ++i){
            if(expression[i] == '('){
                count++;
            }else if(expression[i] == ')'){
                count--;
            }
            if(expression[i] == ','&&count == 0){
                ans.push_back(parseBoolExpr(expression.substr(start,i-start)));
                start = i + 1;
            }
        }
        ans.push_back(parseBoolExpr(expression.substr(start,n+1-start)));
        
        return ans;
    }
    
    /*merge all of result*/
    bool merge(const vector<bool> & res,char op){
        bool ans = false;
        
        if(op == '|'){
            ans = false;
        }else if(op == '&'){
            ans = true;
        }
        
        for(auto b : res){
            if(op == '|'){
                ans |= b;
            }else if(op == '&'){
                ans &= b;
            }
        }
        
        return ans;
    }
    
    bool parseBoolExpr(string expression) {
        bool ans = true;
        int n = expression.size();
        int i = 0;
                
        while(i < n){
            switch(expression[i]){
                case 't':
                    return true;
                    break;
                case 'f':
                    return false;
                    break;
                case '!':
                    return !parseBoolExpr(expression.substr(2,n-3));
                    break;
                case '|':
                    return merge(split(expression.substr(2,n-3)),'|');
                    break;
                case '&':
                    return merge(split(expression.substr(2,n-3)),'&');
                    break;
                case '(':
                    return parseBoolExpr(expression.substr(1,n-2));
                    break;
                default:
                    break;
            }
            ++i;
        }
        
        return ans;
    }
};
```

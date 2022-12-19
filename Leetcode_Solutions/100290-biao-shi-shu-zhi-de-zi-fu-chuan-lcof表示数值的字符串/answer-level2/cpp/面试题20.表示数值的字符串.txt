### 解题思路
代码思路：判断字符串中有无'e'或'E'，如有则分开判断e两边子串（整数和指数）是否都为数值，如无则只需判断是否为数值即可
执行用时 :8 ms, 在所有 C++ 提交中击败了39.74%的用户
内存消耗 :6.2 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    bool judgeBase(string s){
        bool point=false;
        bool result=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='+'||s[i]=='-'){
                if(i!=0){
                    result=false;
                    break;
                }
            }
            else if(s[i]=='.'){
                if(point){
                    result=false;
                    break;
                }
                point=true;
            }
            else if(s[i]<'0'||s[i]>'9'){
                result=false;
                break;
            }
            else result=true;     
        }
        return result;
    }
    bool judgeIndex(string s){
        bool result=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='+'||s[i]=='-'){
                if(i!=0){
                    result=false;
                    break;
                }
            }
            else if(s[i]<'0'||s[i]>'9'){
                result=false;
                break;
            }
            else result=true;
        }
        return result;
    }

    bool isNumber(string s) {
        int start=s.find_first_not_of(' ');
        if(start==string::npos)return false;
        int end=s.find_last_not_of(' ');
        s=s.substr(start,end-start+1);
        int e=s.find_first_of("eE");
        if(e==string::npos){
            return judgeBase(s);
        }
        else{
            return judgeBase(s.substr(0,e))&&judgeIndex(s.substr(e+1));
        }
    }
};
```
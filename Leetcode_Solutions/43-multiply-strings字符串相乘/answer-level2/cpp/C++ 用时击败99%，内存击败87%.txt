代码写的比较长，供大家参考。
```
class Solution {
public:
    void trim(string &s) {//我发现题目的测试用例输入不合法，我就自己写了个函数让它的输入合法
        for(int i=0;i<s.size();i++){
            if(!isalnum(s[i]))
                s.replace(i,1,"");
        }
    }
    
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        trim(num1);
        trim(num2);
        int n1_size = num1.size();
        int n2_size = num2.size();
        string ret(n1_size + n2_size,'0');
        
        for(int i=0;i<n1_size;i++){
            for(int j=0;j<n2_size;j++){
                int tmp = (num1[i]-'0') * (num2[j]-'0') + (ret[i+j+1]-'0');
                ret[i+j+1] = (char)((tmp%10)+'0');
                int append = tmp/10;
                
                for(int k = i+j;append>0;k--){//做进位
                    tmp = (ret[k]-'0') + append;
                    ret[k] = (char)((tmp%10) + '0');
                    append = tmp/10;
                }
            }
        }
        for(int i=0;i<ret.size();i++){
            if(ret[i] == '0')
                continue;
            
            ret = ret.substr(i,-1);//去掉字符串头部的0
            break;
        }
        
        return ret;
    }
};
```

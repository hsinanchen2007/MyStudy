### 解题思路
左测试用例      右答案
/...           /...
/..hidden      /..hidden
/.heal.        /.heal.

本题栈内一个目录表示为
**目录名/**
### 代码

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        stack<char> s;
        stack<char> re_s;
        string valid;
        //num用于统计连续的**.** 的个数
        int num=0;
        //长度不为0至少是根目录
        if(path.length()==0) return "";
        for(int i=1;i<path.length();i++){
            //统计连续的**.** 的个数
            if(path[i]=='.'){
                if(num==0) num=1;
                if(path[i-1]=='.') num++;
            }
            //不是‘/’一律入栈
            if(path[i]!='/'){
                s.push(path[i]);
                if(path[i]!='.') num=0;
                
            }
            //对于目录是‘/..’ 或 ‘/.’ 做pop操作
            if((i==path.length()-1) || (path[i]=='/')){
                
                if(num==1){s.pop();num=0;continue;}
                // ‘/..’弹出上级目录
                if(num==2){
                    s.pop();s.pop();
                    if(!s.empty()) s.pop();
                    while((!s.empty())&&(s.top()!='/')){
                        s.pop();  
                    }
        
                        num=0;
                        continue;
                    }
                
            }
            //防止重复括号入栈
            if((path[i]=='/')&& (path[i-1]!='/')){
                s.push('/');
            }
            
           
            
            
        }
        
        //弹出多余的‘/’
        if(!s.empty()) {
            if(s.top()=='/')
            s.pop();
        }
        else return "/";
        //re_s是s栈的反转栈
        while(!s.empty()){
            re_s.push(s.top());
            s.pop();  
        }
        
        valid.push_back('/');
        while((!re_s.empty())){
                valid.push_back(re_s.top());
                re_s.pop();  
        }
        return valid;

    }
};
```
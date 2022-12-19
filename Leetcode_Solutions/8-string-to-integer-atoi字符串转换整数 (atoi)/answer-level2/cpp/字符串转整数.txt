### 解题思路
丑陋无比的代码。。反正过了
--后面有修改的代码
### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int i=0;
        while(i<str.size()&&str[i] == ' ')
            i++;
        str = str.substr(i,str.size()-i);           //丢掉开头空格
        
        string s="";
        bool flag=1;        //判断正负
        for(i = 0;i < str.size();i++){
            if(i==0){
                if(str[i] == '-'){
                    flag = 0;
                    continue;
                }
                else if(str[i] == '+')
                    continue;
                else if(str[i] >= '0' && str[i] <= '9')
                    s += str[i];
                else return 0;
            }
            else{
                if(str[i] >= '0' && str[i] <= '9')
                    s += str[i];
                else    break;
            }
        }
        long long res=0;
        for(i = 0;i < s.size();i++){
            int temp = s[i] - '0';
            res = res*10 + temp;
        if(res > INT_MAX)   break;
        }
        if(!flag)
            res *= -1;
        if(res < INT_MIN)   return INT_MIN;
        if(res > INT_MAX)   return INT_MAX;
        return res;
        
    }
};
```

修改后
```cpp
class Solution {
public:
    int myAtoi(string str) {
        long long res=0;    //结果
        int i=0;            //str下标
        bool flag=1;        //判断正负
        while(i<str.size()&&str[i] == ' ')      //排除开头的空格
            i++;                
        if(str[i] == '-'){                      //正负号
            flag=0;
            i++;
        }
        else if(str[i] == '+')
            i++;
       
        for(i;i < str.size();i++){
            if(str[i] < '0' || str[i] > '9')
                break;
            int temp = str[i] - '0';
            res = res*10 + temp;
            if(res > INT_MAX){
                if(flag == 0)   return INT_MIN;
                else    return INT_MAX;
            }
        }
        if(!flag)
            res *= -1; 
        return res;
        
    }
};
```

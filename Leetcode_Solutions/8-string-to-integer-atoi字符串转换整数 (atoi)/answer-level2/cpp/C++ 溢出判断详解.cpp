```
    //INT_MAX =  2147483647
    //INT_MIN = -2147483648
    //设 res保存之前的正数值 flag = 1为正数 flag = -1为负数 d表示当前位要加的数
    //因此若res > 214748364 时 继续计算就一定会溢出 即res > INT_MAX/10 时溢出
    //    若res = 214748364    即res == INT_MAX/10 
    //                     则对于正数 当此时加的数d>=7 则会正溢出 即 flag==1 && d>=7 正溢出 
    //                     对于负数 当此时加的数d>=8 则会负溢出   即 flag==-1 && d>=8 负溢出
    int myAtoi(string str) {
        int i = 0;//游标
        while(i < str.size() && str[i]==' ') i++;//去除空格
        int flag = 1;//符号标志 1为正数 -1为负数
        if(str[i]=='-') flag = -1,i++; //读取符号位
        else if(str[i]=='+') i++;
        int res = 0;
        for( ; i<str.size()&&str[i]>='0' && str[i]<='9'; i++){//读取数值位
            int d = str[i]-'0';//该位值
            if(res > INT_MAX / 10) return flag==-1 ? INT_MIN : INT_MAX;//必然溢出
            if(res == INT_MAX / 10){//可能溢出
                if(flag==1 && d >= 7) return INT_MAX;//正溢出
                if(flag==-1 && d >= 8) return INT_MIN;//负溢出
            }
            res = res*10 + d;
        }
        return flag*res;//返回结果 符号位*数值位    
    }
```

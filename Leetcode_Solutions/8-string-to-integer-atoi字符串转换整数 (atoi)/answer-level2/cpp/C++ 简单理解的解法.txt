```
class Solution {
public:
    int myAtoi(string str) {
        long long rs=0; int flag=1; int pos=0;
        int len=str.size(); //数组长度
        int x1=-2147483648,x2=2147483647;
        for(int i=0;i<len;i++){
            if(str[i]!=' '&&flag) //第一个非空字符
            {

                if(str[i]=='+')
                {
                    pos=1;
                }
                else if(str[i]=='-'){
                    pos=-1;
                }else if(str[i]>='0'&&str[i]<='9'){ //第一个字符是数字
                    pos=1;
                    rs=str[i]-'0';
                }
                else
                    break;
                flag=0;
                continue;
            }
            if(flag==0){

            if(str[i]>='0'&&str[i]<='9'&&rs<x2){
                rs=rs*10+(str[i]-'0');
            }
            else
            {
                break; //结束循环
            }
            }


        }
        rs=rs*pos;
        if(rs>=x1&&rs<=x2){
                return rs;
        }
        if(rs<x1){
            return x1;
        }

        return x2;

    }
};
```

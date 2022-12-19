一个循环下来，用了较多的判断,首先把常用的ascii码列出来以便处理需要；INT_MIN  INT_MAX可以直接用
为了方便人员阅读，都强制进行了char to int的转换
为了避免出现 分割的数字，添加了bool变量，只要处理到了数字，这个变量就为true
```
int myAtoi(char * str){
    //ASCII 0:48  9:57  space:32  minus:45  plus:43
    int num=0,flag=1,c;
    bool b=false;
    for(; *str!='\0';str++){
        c=(int)*str;
        if(c==32&&!b) //判断空格且未遇到数字 + -三种字符
            continue;
        else if(c==43&&!b){ //判断+号，bool置为true
            b=true;
            flag=1;
            continue;
        }
        else if(c==45&&!b){ //判断-号，bool置为true
            b=true;
            flag=-1;
            continue;
        }else if(c<48||c>57){ //判断非数字、+ - 三种情况，直接跳出。
             break;
        }else if(c>=48&&c<=57){    //判断数字，bool置为true
            b=true;        
            c=c-48; //转为十进制，方便阅读
            if(num==(INT_MAX/10)){  //每次计算前为了避免溢出，先除以10进行计算
                if(c<=7)  //小于7不会溢出
                    ;
                else if(flag==1&&c>7)
                    return INT_MAX;
                else if(flag==-1&&c>=8) 
                    return INT_MIN;
            }else if(num>(INT_MAX/10)){

                if(flag==1)
                    return INT_MAX;
                else if(flag==-1) 
                    return INT_MIN;
            }
            num=num*10+c; 
        }  
    }
    return num*flag;
}
```

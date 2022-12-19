### 解题思路
此处撰写解题思路

### 代码

```c
# define num(x) ( x>='0' && x<='9' )
# define int_max_safe(x,y) ( x<INT_MAX/10 || ( x==INT_MAX/10 && y<=INT_MAX%10 )  )
# define int_min_safe(x,y) ( x>INT_MIN/10 || ( x==INT_MIN/10 && y>=INT_MIN%10 ) )

int myAtoi(char * str){
    int convert_flag=0,convert_ans=0;
    
    while ( *str ) {
        if ( !convert_flag && *str==' ' ) ;  //如果还没开始转换且遇到空格
        else if ( !convert_flag && *str=='-' ) convert_flag=-1; //如果还没开始转换遇到负号
        else if ( !convert_flag && *str=='+' ) convert_flag=1; //如果还没开始转换遇到正号
        else if ( !convert_flag && num(*str) ) {  //如果还没开始转换遇到数字
            convert_flag=1;
            convert_ans=convert_ans*10+*str-'0';
        }
        else if ( !convert_flag ) return 0;//如果还没开始转换遇到无效字符
        
        else if ( 1==convert_flag && num(*str) && int_max_safe( convert_ans,*str-'0' ) )//正数开始转换,当转换后值<=INT_MAX
            convert_ans=convert_ans*10+(*str-'0');
        else if ( -1==convert_flag && num(*str) && int_min_safe( convert_ans,'0'-*str ) )//负数开始转换,当转换后值>=INT_MIN
            convert_ans=convert_ans*10+('0'-*str);
        else if ( !num(*str) ) return convert_ans; //如果转换过程中遇到非数字
        else if ( !int_max_safe( convert_ans,*str-'0' ) ) return INT_MAX; //如果转换过程中正数溢出
        else if ( !int_min_safe( convert_ans,'0'-*str ) ) return INT_MIN; //如果转换过程中负数溢出
        
        str++;
    }
    return convert_ans;
}
```
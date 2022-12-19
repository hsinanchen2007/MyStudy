### 解题思路
此处撰写解题思路
好多坑，不写不知道，不测不知道
### 代码

```c
int myAtoi(char * str){
long a=0;
int flag=0;
int flag1=0;
while(*str != '\0'){
  if(*str != ' '){
      if(*str == '-'){
          if(flag!=0)
             return 0;
          flag=1;
      }else
       {
        if(*str == '+'){
           
            if(flag == 1 || flag1 == 1){
            return 0;
             flag1=1;
            }
            str++;
        }
       while('0' <= *str && *str <= '9'){
        a=a*10+*str-'0';
        if(flag !=0){
        if(fabs(a)>2147483648){
            return -2147483648;
         }
        }
        else{
          if(a > 2147483647)
             return 2147483647;
         }
        str++;
         }
       goto loop;
        }
     
  }else{
  if(flag != 0 || flag1 !=0)
   return 0;
  }
   str++;
}

loop:
if(flag==1)
return (0-a);
else
return a;
}
```
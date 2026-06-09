### 解题思路
先跳过空格，再用switch语句判断四种情况，就是类似的代码重复得都点多

### 代码

```c
int myAtoi(char * str){
    //jump space
    int i=0;
    int length=strlen(str);
    long max=2147483647,min=-2147483648;//设置上下界
    long long ans=0;
    int flag=0;
    while(str[i]!='\0'&&str[i]==' ')
        i++;//跳过空格
    //return i;
    switch(str[i]){
        case '+':{
            i++;
            while(str[i]!='\0'){
                if(str[i]<='9'&&str[i]>='0'){
                    ans=ans*10+(str[i]-'0');
                    if(ans>max)
                        return max;
                    i++;
                }else
                    break;
            }
            break;
        }
        case '-':{
            i++;
            while(str[i]!='\0'){
                if(str[i]<='9'&&str[i]>='0'){
                    ans=ans*10+(str[i]-'0');
                    if(-ans<min)
                        return min;
                    i++;
                }else
                    break;
            }
            ans=-ans;
            break;
        }
        case '\0':
            break;
        default:{
             while(str[i]!='\0'){
                if(str[i]<='9'&&str[i]>='0'){
                    ans=ans*10+(str[i]-'0');
                    if(ans>max)
                        return max;
                    i++;
                }else
                    break;
            }
            break;
        }
    }
    return ans;
}
```
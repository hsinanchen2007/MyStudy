### 解题思路
此处撰写解题思路
需要注意 + - 和取值范围的细节，提交了4次，终于通过了
### 代码

```c
int myAtoi(char * str){
    int ret = 0;
    bool first = false;
    int zs = 1;
    char *tmp = str;
    if(NULL == str){
        return 0;
    }

    while(tmp < &str[strlen(str)]){
        if(!first){
            if(*tmp >= '0' && *tmp <= '9'){
                first = true;
                if(ret > INT_MAX / 10|| ret == INT_MAX/10 && *tmp - '0' > INT_MAX - INT_MAX/10*10) {
                    return zs == 1 ? INT_MAX:INT_MIN;
                }
                ret = ret * 10 + (*tmp - '0');
            }else if(*tmp == '-'){
                zs = -1;
                first = true;
            }else if(*tmp == '+'){
                zs = 1;
                first = true;
            }else if(*tmp == ' '){
                tmp++;
                continue;
            }else{
                break;
            }
        }else{
            if(*tmp >= '0' && *tmp <= '9'){
                if(ret > INT_MAX / 10|| ret == INT_MAX/10 && *tmp - '0' > INT_MAX - INT_MAX/10*10) {
                    return zs == 1 ? INT_MAX:INT_MIN;
                }
                ret = ret * 10 + (*tmp - '0');
            }else{
                break;
            }
        }
        tmp++;
    }

    return ret * zs;
}
```
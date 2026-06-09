### 解题思路
此处撰写解题思路

### 代码

```c
char * addBinary(char * a, char * b){
    int result_len;
    int a_len=strlen(a);
    int b_len=strlen(b);
    char* a_p=a;
    char* b_p=b;
    char flag='0';
    result_len=a_len>b_len?a_len:b_len;
    char* result=(char*)malloc(sizeof(char)*(result_len+2));
    result=result+result_len+1;
    a_p=a+a_len-1;
    b_p=b+b_len-1;
    *(result--)='\0';
    while(1){
        if((*a_p)=='1'&&(*b_p)=='1'){
            (*result)=flag=='1'?'1':'0';
            flag='1';
        }
        else if((*a_p)=='1'||(*b_p)=='1'){
            (*result)=flag=='1'?'0':'1';
        }
        else{
            (*result)=flag=='1'?'1':'0';
            flag='0';
        }
        if(a!=a_p&&b!=b_p){
            a_p--;b_p--;
        }
        else if(a!=a_p){
            a_p--;
            *b_p='0';
        }
        else if(b!=b_p){
            b_p--;
            *a_p="0";
        }
        else{
            *a_p='0';
            *b_p='0';
            if(flag=='0'){break;}
        }
        result--;
    }
    return result;
}
```
### 解题思路
else绝对不能少
如果少了，下一行代码result+=map(s[i]);也会执行，比如IV result=0-1又执行result=0-1-1
### 代码

```c
char norm[]= "IVXLCDM";
int number[]={1,5,10,50,100,500,1000};

int map(char c){
    for(int i=0;i<strlen(norm);i++){
        if(norm[i]==c){
            return number[i];
        }
    }
    return 0;
}

int romanToInt(char * s){
    int result=0;
    //printf("%d\n",strlen(s));
    for(int i=0;i<strlen(s)-1;i++){
        if(map(s[i])<map(s[i+1])){
            result-=map(s[i]);
        }
        else{//else绝对不能少
            result+=map(s[i]);
        }
        
    }
    result+=map(s[strlen(s)-1]);
    return result;

}
```
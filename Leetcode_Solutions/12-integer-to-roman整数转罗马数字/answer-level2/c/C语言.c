```
typedef struct dictnode{
    char str[3];
    int val;
}dictnode;
void backtrack(int num,dictnode* dict,int i,char *ret,int len);
char * intToRoman(int num){
    dictnode dict[13]={{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}};
    char *ret=(char*)malloc(200);
    memset(ret,'/0',200);
    backtrack(num,dict,12,ret,0);
    return ret;
}
void backtrack(int num,dictnode* dict,int i,char *ret,int len){
    if(i<0)return;
    if(num==0)return;
    while(dict[i].val>num){
        i--;
    }
    num=num-dict[i].val;
    int l=(int)strlen(dict[i].str);
    strcpy(ret+len,dict[i].str);
    len=len+l;
    backtrack(num,dict,i,ret,len);
}
```

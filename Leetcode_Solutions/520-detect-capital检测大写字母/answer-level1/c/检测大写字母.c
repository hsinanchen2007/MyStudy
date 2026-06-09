### 解题思路
常规思路，2次循环3次判断

### 代码

```c
bool detectCapitalUse(char * word){
    int i,j;
    j=strlen(word);
    char *cmp=(char*)malloc(sizeof(char)*(j+1));
    cmp[j]='\0';
    strcpy(cmp,word);
    for(i=0;word[i]!='\0';i++){
        word[i]=word[i]>='a'&&word[i]<='z'?word[i]-32:word[i];    //转大写
        //word[i]=word[i]&'_';    //转大写，实际用的较少，耗时多
    }
    if(strcmp(cmp,word)==0) return true;
    for(i=0;word[i]!='\0';i++){
        word[i]=word[i]>='A'&&word[i]<='Z'?word[i]+32:word[i];    //转小写
        //word[i]=word[i]|' ';    //转小写
    }
    if(strcmp(cmp,word)==0) return true;
    word[0]=word[0]>='a'&&word[0]<='z'?word[0]-32:word[0];        //首字母大写
    if(strcmp(cmp,word)==0) return true;
    return false;
}
```
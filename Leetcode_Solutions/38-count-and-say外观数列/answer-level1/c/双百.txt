### 解题思路
此处撰写解题思路

### 代码

```c
char* nextarr(char *ch){
    char* sh=(char*)malloc(4501*sizeof(char));
    sh[4500]='\0';
    for(int i=0;i<4500;i++) sh[i]=-1;
    int j=1,q=4499;
    for(int i=4499;ch[i]!=-1;i--){
        if(ch[i-1]==ch[i]) {
            j++;
            continue;
        }
        else{
            sh[q]=ch[i];
            sh[q-1]=j+'0';
            j=1;
            q=q-2;
        }
    }
    return sh;
} 
char * countAndSay(int n){
    char* ch=(char*)malloc(4501*sizeof(char));
    ch[4500]='\0';
    for(int i=0;i<4500;i++) ch[i]=-1;
    int i;
    ch[4499]='1';
    for(i=1;i<n;i++){
        ch=nextarr(ch);
    }
    while(*ch==-1){
        ch++;
    }
    
    return ch;
}
```
 

### 代码

```c
char* replaceSpace(char* s){
    char* ss=(char*)malloc(sizeof(char)*14000);
    int j=0;
    for(int i=0;s[i];i++,j++){
        if(s[i]==' '){
            ss[j]='%';
            ss[j+1]='2';
            ss[j+2]='0';
            j=j+2;
             
 
        }else{
             ss[j]=s[i];
        }
     
    }
    ss[j]='\0';
    
    return ss;
}
```
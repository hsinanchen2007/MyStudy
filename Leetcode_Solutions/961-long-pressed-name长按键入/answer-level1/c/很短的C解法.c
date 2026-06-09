控制好循环直接判断是否相同就行

```
bool isLongPressedName(char * name, char * typed){
    int len=(int)strlen(name),k=0;
    for(int i=0;i<len;i++){
        if(name[i]==name[i+1]&&name[i]==typed[k++]) continue;
        if(name[i]!=typed[k]) return false;
        while(typed[k]==typed[k+1]) k++; k++;
    }
    return true;
}
```


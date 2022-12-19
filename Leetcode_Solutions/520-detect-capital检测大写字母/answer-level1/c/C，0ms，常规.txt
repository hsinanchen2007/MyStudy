如果首字母是小写，出现大写则0；
如果首字母是大写，从第二个字母开始，全大写或全小写则为1。

```
bool detectCapitalUse(char * word){
    int s,b;
    s=*word>'Z'?1:0;
    for(int i=1;i<strlen(word);i++){
        if(s){
            if(word[i]<'a')
            return 0;
        }
        else{
            b=word[1]<'a'?1:0;
            if((word[i]>'Z'&&b)||(word[i]<'a'&&b==0))
            return 0;
        }
    }
    return 1;
}
```

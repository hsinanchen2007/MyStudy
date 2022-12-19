如果第一个和第二个字母都为大写，则后续都应为大写；如果第一个字母为大写而第二个字母为小写，则后续都应为小写；如果第一个字母为小写，则后续都应为小写。
```c
bool detectCapitalUse(char * word){
    int length=0,i;
    while(word[length]!=0) length++;
    if(word[0]>='A'&&word[0]<='Z'){
        if(word[1]>='A'&&word[1]<='Z'){
            for(i=1;i<length;i++)
                if(word[i]>='a'&&word[i]<='z') return 0;
        }
        else{
            for(i=1;i<length;i++)
                if(word[i]>='A'&&word[i]<='Z') return 0;
        }
    }
    else{
        for(i=0;i<length;i++)
            if(word[i]>='A'&&word[i]<='Z') return 0;
    }
    return 1;
}
```
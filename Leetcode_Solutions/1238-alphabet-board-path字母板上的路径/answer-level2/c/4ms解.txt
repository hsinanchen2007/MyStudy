思路：先创建一个字母板（二维字符数组），调整时把当前字符与目标字符减'A'，这样从'a'到'z'就变成了从0到25，然后先与下一个目标字符列对齐（两个字符减'a'后对5取余进行比较），然后再调整行对齐（两个字符减'a'后除以5进行比较），如果当前位置为'z'时，下一个目标字符若不是'z'则先将当前位置向上调整一步到'u'的位置，再继续进行相关调整。
```
char cc[6][5]={{'a','b','c','d','e'}, {'f','g','h','i','j'}, {'k','l','m','n','o'}, {'p','q','r','s','t'}, {'u','v','w','x','y'}, {'z'}};
char * alphabetBoardPath(char * target){
    char* p=(char*)malloc(strlen(target)*25*sizeof(char));
    int j=0,k=0,n=0;
    for(int i=0;i<strlen(target);i++){
        if(i==0){
            int q=(target[i]-'a')/5;
            for(int j=0;j<q;j++)
                p[n++]='D';
            q=(target[i]-'a')%5;
            for(int j=0;j<q;j++)
                p[n++]='R';
            p[n++]='!';
        }
        else{
            if(target[i-1]!=target[i]&&target[i-1]=='z'){
                p[n++]='U';
                target[i-1]='u';
            }
            if(target[i]==target[i-1]){
                p[n++]='!';
            }
            else if((target[i]-'a')/5==(target[i-1]-'a')/5){
                if(target[i]>target[i-1])
                    for(int j=0;j<target[i]-target[i-1];j++)
                        p[n++]='R';
                else
                    for(int j=0;j<target[i-1]-target[i];j++)
                        p[n++]='L';
                p[n++]='!';
            }
            else if((target[i]-'a')/5>(target[i-1]-'a')/5){
                if(target[i]-((target[i]-'a')/5-(target[i-1]-'a')/5)*5>target[i-1])
                    for(int j=0;j<target[i]-((target[i]-'a')/5-(target[i-1]-'a')/5)*5-target[i-1];j++)
                        p[n++]='R';
                else
                    for(int j=0;j<target[i-1]-target[i]+((target[i]-'a')/5-(target[i-1]-'a')/5)*5;j++)
                        p[n++]='L';
                for(int j=0;j<((target[i]-'a')/5-(target[i-1]-'a')/5);j++)
                    p[n++]='D';
                p[n++]='!';
            }
            else{
                if(target[i]+((target[i-1]-'a')/5-(target[i]-'a')/5)*5>target[i-1])
                    for(int j=0;j<target[i]+((target[i-1]-'a')/5-(target[i]-'a')/5)*5-target[i-1];j++)
                        p[n++]='R';
                else
                    for(int j=0;j<target[i-1]-target[i]-((target[i-1]-'a')/5-(target[i]-'a')/5)*5;j++)
                        p[n++]='L';
                for(int j=0;j<((target[i-1]-'a')/5-(target[i]-'a')/5);j++)
                    p[n++]='U';
                p[n++]='!';
            }
        }
    }
    p[n]='\0';
    return p;
}
```

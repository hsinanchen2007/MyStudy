代码中，length是字符串的总长度，fre可以理解为频率，period可以理解为周期长度，f在for循环中表示第几个周期。
```c
bool repeatedSubstringPattern(char * s){
    int length=0,fre,i,period,f,flag=0;
    while(s[length]!=0){
        length++;
    }

    for(fre=2;fre<length;fre++){
        flag=0;
        if(length%fre!=0) continue;
        period=length/fre;
        for (f=1;f<fre;f++){
            for(i=0;i<period;i++)
                if (s[i]!=s[f*period+i]) break;
            if (i!=period) break;
        }
        if (f!=fre) continue;
        else {
            flag=1;
            break;}
        }
        
    if (fre==length){
        for(i=1;i<length;i++)
            if(s[i]!=s[0]) break;
        if (i==length) flag=1;
    }
    if(flag==1) return 1;
    else return 0;
}
```

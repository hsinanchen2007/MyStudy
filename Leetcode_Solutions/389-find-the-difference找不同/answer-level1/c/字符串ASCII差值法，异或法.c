**差值法**
```

char findTheDifference(char * s, char * t){
    int sum_s=0,sum_t=0;
    for(int i=0;i<strlen(t);i++){
        if(i<strlen(t)-1)sum_s +=s[i];
        sum_t +=t[i];
    }
    return sum_t-sum_s;
}

```
**异或法**
```

char findTheDifference(char * s, char * t){
    int i=0,sum=0;
    for(i=0;i<strlen(s);i++) sum ^= t[i]^s[i];
    return (sum^t[i]);
}
```

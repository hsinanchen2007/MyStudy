

```
#define MAX_LEN 20
char * intToRoman(int num){

    char *R="IVXLCDM";
    int j=0;
    char *ret=(char*)malloc(MAX_LEN);
    int i=MAX_LEN-1;
    ret[i--]=0;
    while(num)
    {
        int digi=num%10;
        switch(digi)
        {
            case 9:
                ret[i--]=R[j+2];
                ret[i--]=R[j];
                break;
            case 8:
                ret[i--]=R[j];
            case 7:
                ret[i--]=R[j];
            case 6:
                ret[i--]=R[j];
            case 5:
                ret[i--]=R[j+1];    
                break;
            case 4:
                ret[i--]=R[j+1];
                ret[i--]=R[j];
                break;
            case 3:
                ret[i--]=R[j];
            case 2:
                ret[i--]=R[j];
            case 1:
                ret[i--]=R[j];          
                break;
        }
        num/=10;
        j+=2;
    }
    return ret+i+1;
}
```


### 解题思路
哎，这么简单的一道题竟然也花了那么长时间。不应该。

### 代码

```c

#define CHUSHU 16
#define QISHI 10

char * toHex(int num){
    unsigned int beiChuShu = num;
    unsigned int shang = 0;
    unsigned int yu = 0;
    int i = 0;
    char result[50] = {'\0'}; 

    if(beiChuShu < 0) {
        unsigned int quFan = pow((double)2, (double)32) + num;
        printf("quFan = %d\n",quFan);
        unsigned int buMa = quFan;// + 1;
        beiChuShu = buMa;
    }
    
    while(CHUSHU <= beiChuShu) {
        yu = beiChuShu % CHUSHU;
        printf("yu = %d\n",yu);
        if(yu < 10) {
            result[i] = (char)((int)'0' + yu);
        }
        else {
            result[i] = (char)((int)'a' + (yu - QISHI));
        }
        beiChuShu = (int)(beiChuShu / CHUSHU);
        //printf("%c\n",result[i]);
        i++; 
    }

    printf("beiCHUShu = %d\n",beiChuShu);

    if(beiChuShu < 10) {
        result[i] = (char)((int)'0' + beiChuShu);
    }
    else {
        result[i] = (char)((int)'a' + (beiChuShu - QISHI));
    } 

    int len = strlen(result);   
    printf("len = %d\n",len);
    char *ret = (char *)malloc((len + 1)  * sizeof(char));
    ret[len] = '\0';
    
    for(i = len - 1 ; 0 <= i; i --) {
        ret[len - 1 - i] = result[i];
        printf("%c",result[i]);
    }
    printf("\n");

    return ret;
}
```
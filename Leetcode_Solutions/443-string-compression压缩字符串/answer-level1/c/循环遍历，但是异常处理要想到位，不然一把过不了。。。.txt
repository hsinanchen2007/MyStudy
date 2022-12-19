### 解题思路
按照直觉来写。

### 代码

```c
int compress(char* chars, int charsSize){
    if(chars == NULL){
        return 0;
    }
    if(charsSize == 1){
        return 1;
    }
    int setIdx = 0;

    // int tmp = 123456;
    // while(tmp / 10 != 0){
    //     int yu = tmp % 10;
    //     tmp /= 10;
    //     printf("%d ",yu);
    // }
    // printf("%d ",tmp);
    // printf("\n");
    char charNums[1000];
    memset(charNums,0,sizeof(charNums));

    for(int i = 0; i < charsSize; ){
        int now = i;
        int j = 0;
        memset(charNums,0,sizeof(charNums));

        
        while(((now + j) < charsSize) && (chars[now+j] == chars[now])){
            ++j;
            // printf("%d , ",j);
        }
        // printf("\n");
        // printf("now %d ", now);

        // printf("j: %d\n",j);
        i += j;
        chars[setIdx++] = chars[now];
        if(j == 1){
            continue;
        }
        sprintf(charNums,"%d",j);//charNums
        
        int jLen = strlen(charNums);
        // printf("charNums: %s len: %d\n",charNums,jLen);
        for(int jj = 0; jj < jLen;++jj){
            chars[setIdx++] = charNums[jj];
        }

        // chars[setIdx++] = +'0';
    }

    return setIdx;
}
```
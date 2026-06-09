

```c
#define LEN 58
int longestPalindrome(char * s){
    if(strlen(s) == 0) {
        return 0;
    }
    int *temp = (int *)malloc(sizeof(int) * LEN);
    memset(temp,0,LEN);
    for(int i = 0; i < LEN; i++) {
        temp[i] = 0;
    }
    //printf("%d",'z'-'A');
    for(int i = 0; i < strlen(s); i++) {
        temp[s[i] - 'A']++;
        //printf("%d,%d ",s[i] - 'A',temp[s[i] - 'A']);
    }
    //printf("\n");
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for(int i = 0; i < LEN; i++) {
        if(temp[i] % 2 != 0) {
            sum1 += temp[i] - 1;
            sum3 = 1;
        } else {
            sum2 += temp[i];
        }
    }
    printf("%d,%d ",sum1,sum2);
    return (sum1 + sum2 + sum3);
}
```
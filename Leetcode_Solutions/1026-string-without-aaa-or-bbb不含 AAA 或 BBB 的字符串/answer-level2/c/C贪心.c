### 解题思路
如果 B-A 大于 2  那就先拼凑 bba,  如果是B和A之差 在1和-1之间， 先凑ab 或者ba， 同理A-B大于2  就是aab

### 代码

```c
char * strWithout3a3b(int A, int B){
    char* ret = (char*)malloc(sizeof(char) * (A + B + 1));
    
    int count = 0;
    
    while (B != 0 && A != 0) {
        if (B - A >= 2 && A != 0) {
            ret[count++] = 'b';
            ret[count++] = 'b';
            ret[count++] = 'a';
            B -= 2;
            A -= 1;
        } else if (B - A <= 1 && B - A >= -1 && A != 0 && B != 0) {
            ret[count++] = 'b';
            ret[count++] = 'a';
            B -= 1;
            A -= 1;
        } else if (B != 0){
            ret[count++] = 'a';
            ret[count++] = 'a';
            ret[count++] = 'b';
            A -= 2;
            B -= 1;
        }
    }
    //printf("%d\n", tempB);
    while (B != 0) {
        ret[count++] = 'b';
        B--;
    }
    while (A != 0) {
        ret[count++] = 'a';
        A--;
    }
    ret[count] = '\0';

    return ret;
}
```
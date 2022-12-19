### 解题思路
1. 如果两个均为空字符串, 返回True
2. 如果两个字符串长度不等, 返回False
3. 最多旋转len(A)次
4. 循环旋转, 对比字符串, 最少1次, 最多len次, 如果相同就返回True
5. 如果旋转了len次都不相同, 直接返回False
### 代码

```c
bool rotateString(char * A, char * B){
    if (strlen(A)==0 && strlen(B)==0) return true;
    if (strlen(A) != strlen(B)){ return false; }
    int len = strlen(A);
    char temp;
    for (int i=0; i<len; i++){
        temp = A[0];
        for (int j=0; j<len-1; j++){
            A[j] = A[j+1];
        }
        A[len-1] = temp;
        if (strcmp(A, B) == 0){
            return true;
        }
    }

    return false;
}
```
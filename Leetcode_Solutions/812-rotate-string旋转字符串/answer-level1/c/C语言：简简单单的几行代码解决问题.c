![QQ截图20190630154501.png](https://pic.leetcode-cn.com/9e32d4337ce98a2a38eeec013ecc499d86b7282f51e8b266c13b57539223d367-QQ%E6%88%AA%E5%9B%BE20190630154501.png)

```
bool rotateString(char * A, char * B){
    if (strlen(A) != strlen(B)) return false;
    if (!strlen(A)) return true;
    int my_strlen = strlen(A); 
    int i = 0;
    int j = 0;
    for (i = 0; i < my_strlen; ++i) {
        int tmp = i;
        for (j = 0; j < my_strlen; ++j) {
            if (A[tmp++] != B[j]) break;
            tmp %= my_strlen;
        }
        if (j >= my_strlen) return true;
    }

    return false;
}
```

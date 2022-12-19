### 解题思路
双指针

### 代码

```c
char * reverseOnlyLetters(char * S){
    int i = 0; 
    int j = strlen(S) - 1;
    while(i <= j) {
        if (!isalpha(S[i])) {
            i++;
        } else if (!isalpha(S[j])){
            j--;
        } else {
            char tmp = S[i];
            S[i] = S[j];
            S[j] = tmp;
            i++, j--;
        }
    }
    return S;
}
```
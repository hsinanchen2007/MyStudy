### 解题思路
排序，难点：需要记得ASCII对应的值，如果记不住可以使用 0 <= S[i]-'a' <26或者0 <= S[i]-'A' <26来替换
### 代码

```c
char * reverseOnlyLetters(char * S){
    int i = 0;
    int j = strlen(S) -1;
    while(i < j) {
        while(i < j && !((S[j] >=65 && S[j] <= 90 ) || (S[j] >=97 && S[j] <= 122)) ) {
            j--;
        }

        while(i < j && !((S[i] >=65 && S[i] <= 90 ) || (S[i] >=97 && S[i] <= 122)) ) {
            i++;
        }

        int temp = S[i];
        S[i] = S[j];
        S[j] = temp;
        i++;
        j--;
    }
   return S;
}
```
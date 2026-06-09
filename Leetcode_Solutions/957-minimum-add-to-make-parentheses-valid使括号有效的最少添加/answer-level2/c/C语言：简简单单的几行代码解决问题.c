```
int minAddToMakeValid(char * S){
    if (S == NULL || S[0] == '\0') return 0;
    int top = -1, num = 0,stack[1024];
    for (int i = 0; S[i]; ++i) {
        if (S[i] == '(') stack[++top] = '(';
        else {
            if (top >= 0) --top;
            else          ++num;
        }
    }
    return (top < 0 ? num : (num + top + 1));
}
```

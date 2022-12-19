```
    int len_S = strlen(S), sum = 0, count = 1;
    for (int i = 1; i < len_S; i++){
        if(S[i-1] == S[i])
            count++;
        else {
            sum += (count * (count + 1) / 2);
            count = 1;
        }
    }
    return sum + (count * (count + 1) / 2);
```

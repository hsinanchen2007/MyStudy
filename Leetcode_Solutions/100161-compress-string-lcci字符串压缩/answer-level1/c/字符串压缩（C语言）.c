### 解题思路
难度简单的题，但是坑特别多，处处要小心，一不留神，就栽倒了呀！！
当然，用java会简单许多。
### 代码

```c
char* compressString(char* S){
    int length = 0;
    for (length = 0; S[length]; length++);
    char* result = (char*)calloc(sizeof(char), length*2);
    int k = 0;
    for (length = 0; S[length]; ) {
        char oneChar = S[length];
        int count = 1;
        for (int i = length+1; S[i] && S[i] == S[i-1]; i++, count++);
        length+=count;
        result[k++] = oneChar;
        k+=countToChar(result, count, k);
    }
    if (k >= length) {
        return S;
    }
    return result;
}
int countToChar(char *result, int count, int start) {
    int end = start;
    
    while(count) {
        int num = count%10;
        result[end++] = num+'0';
        count/=10;
    }
    int length = end-start;
    --end;
    while(start < end) {
        char tmp = result[start];
        result[start] = result[end];
        result[end] = tmp;
        start++;
        end--;
    }
    return length;
}
```
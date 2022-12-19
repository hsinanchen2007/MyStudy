### 解题思路
1. 坦白来说，如果ret数组定义为ret[50000]就会k产生越界，而ret[100000]就不会。但我不知道为啥。
2. 其中最重要的一点就是将超过10的数字进行存储，因为char【】单位空间只能存放一个字节，所以要使用了一个新的临时数组来分解所有的超过十的数字，再把这个数组赋值给我需要的数组。

### 代码

```c
char* compressString(char* S){
    char ret[100000];
    int i = 0;
    int k = 0;
    int j = 0;

    while (j<strlen(S)){
        j = i+1;
        ret[k++] = S[i];
        while (S[j] != '\0' && S[i] == S[j]){
            j++;
        }
       
        int cnt = 0;
        int temp = j-i;
        int nums[6] = {0};
        while (temp > 0){
            nums[cnt++] = temp%10;
            temp /= 10;
        }
        while (cnt>0){
            ret[k++] = (char)('0'+nums[--cnt]);
        }
        i = j;
    }
    ret[k] = '\0';

    return strlen(ret) < strlen(S) ? ret : S;

}
```
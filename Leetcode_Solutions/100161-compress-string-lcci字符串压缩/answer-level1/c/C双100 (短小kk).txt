### 解题思路
此处撰写解题思路

### 代码

```c
char* compressString(char* S){
    int Ssize = strlen(S), index = 0;
    char* res = (char*) malloc (sizeof(char) * (Ssize+1));
    for(int i = 0, count = 0; i < Ssize; i++){
        count++;
        if( i+1==Ssize || S[i+1]!=S[i] ){
            if (index+2 > Ssize-1)  return S;
            else{
                res[index++] = S[i];
                int digit = (int)log10(count), temp = digit;
                while(count>0){
                    res[index+digit] = count%10+'0';
                    count /= 10;
                    digit--;
                }
                index += temp+1;
                count = 0;
            }
        }
    }
    res[index] = '\0';
    return res;
}
```
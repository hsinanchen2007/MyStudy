### 解题思路
主要就是循环的时候i可以一直循环到S[i]='\0'，这样可以少写一次if
还有我这个在自己的编译器上可以通过但是leetcode过不了。。我估计跟内存有关系吧但是我不懂哈哈哈
虽然没过但是可以借鉴思想嘛

### 代码

```c
char* compressString(char* S){
    int len= strlen(S);
    char*res=(char*)malloc(sizeof(char) * (2 * len));
    char*tmp=(char*)malloc(sizeof(char)*6);
    if(len <= 2)
        return S;
    int cnt = 1;
    res[0] = S[0];
    for(int i =1;i<=len;i++){
        if(S[i] != S[i - 1]){
            int j = 0;
            while(cnt){
                tmp[j++] ='0'+ cnt % 10;
                cnt /= 10;
            }
            strcat(res,tmp);
            res[strlen(res)]=S[i];
            cnt = 1;
        }
        else
            cnt++;
    }
    if (len>strlen(res)) return res;
    return S;
}
```
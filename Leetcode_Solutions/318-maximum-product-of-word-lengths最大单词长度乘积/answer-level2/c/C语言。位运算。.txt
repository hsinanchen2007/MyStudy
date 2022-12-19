
```
/**
 * buf[2*i]存储字符串转换为整数的值，buf[2*i+1]存储字符串长度。
 */
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int maxProduct(char ** words, int wordsSize){
    int* buf  = (int*)malloc(sizeof(int) * wordsSize * 2);
    int i, j, k;
    for(i = 0; i < wordsSize; i++){
        j = 0;
        k = 2 * i;
        buf[k] = buf[k+1] = 0;
        while(words[i][j]){
            buf[k] =  buf[k] | (1 << (words[i][j] - 'a'));
            j++;
        }
        buf[k+1] = j;
    }
    
    int max = 0;
    for(i = 0; i < wordsSize; i++){
        for(j = i + 1; j < wordsSize; j++){
            if(!(buf[2 * i] & buf[2 * j])){
                max = MAX(max, buf[2 * i + 1] * buf[2 * j + 1]);
            }
        }
    }
    
    return max;
}
```

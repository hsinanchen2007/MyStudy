### 解题思路
每一行的字符索引只和该行**第一个字符的索引**以及**行号**有关。

### 代码

```c
char * convert(char * s, int numRows)
{
    int len = strlen(s);
    if(numRows == 1) return s;
    char *ret = (char*)malloc(sizeof(char)*(len+1));
    //第n行（不含首位）的第一个间隔数为 n+2*(numrows-n-1)

    int diff = 2*numRows-2;
    int k = 0;
    int next_index;
    for(int i=0;i<len;i=i+diff){
        ret[k] = s[i];
        k++;
    }
    for(int i=1;i<numRows-1;i++){
        for(int j=i;j<len;j=j+diff){
            ret[k] = s[j];
            k++;
            next_index = j+2*(numRows-i-1);
            if(next_index<len){
                ret[k] = s[next_index];
                k++;
            }

        }
    }
    for(int i=numRows-1;i<len;i=i+diff){
        ret[k] = s[i];
        k++;
    } 
    ret[k] = '\0';
    return ret;
}
```
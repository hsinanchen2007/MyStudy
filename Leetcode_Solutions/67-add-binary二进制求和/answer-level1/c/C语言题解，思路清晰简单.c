```c
先把短的字符数组补齐0，再做二进制加法，注意进位就行。
```
代码块
```
char * addBinary(char * a, char * b){

    int lenA = strlen(a);//找出最大的字符数组的长度length
    int lenB = strlen(b);
    int lenMax = lenA > lenB ? lenA : lenB ;
    int aValue ;
    int bValue ;
    lenMax = lenMax + 2;
    char *c = (char *)malloc(lenMax *(sizeof(char)));
    memset(c,0,lenMax); //初始化
	
    lenMax = (lenMax - 1) - 1 ; //考虑到进位和‘\0’
    while ((lenA > 0) || (lenB > 0)){
        aValue = lenA > 0 ? a[--lenA] - '0': 0;
        bValue = lenB > 0 ? b[--lenB] - '0': 0;
        if(aValue + bValue + c[lenMax] + '0' == '1'){
                c[lenMax] = '1';
                lenMax--;
        }else{
            if(aValue + bValue + c[lenMax] + '0' == '0'){
                c[lenMax] = '0';
                lenMax--;
            }else{
                if(aValue + bValue + c[lenMax] + '0' == '2'){
                c[lenMax] = '0';
                lenMax--;
                c[lenMax] = '1' - '0'; //字符转ASCII码计算a[i] - '0'
                }else{
                c[lenMax] = '1';
                lenMax--;
                c[lenMax] = '1' - '0';
                }
            }
        }
    } 
    c[0] = c[0] +'0';//再转换成ASCII码
    //首位为'0'需要右移
    if(c[0] == '0'){
        c++;
    }
    return c;
    //防止内存泄漏
    free(c);
    c = NULL;
}
```
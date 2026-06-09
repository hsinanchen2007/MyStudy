之前用c++做过一次，最近由于工作需要开始用c语言。

具体的原理就不写了，网上都很详细。

c语言的这个拷贝操作和malloc实在是有太多需要注意的小细节了。

**动态分配的数组如果作为返回值一定要记得在最后加终止符'/0'！！！**


```
代码块


#define min(a,b) ((a) < (b)?(a):(b))
char * longestPalindrome(char * s){
    int len = strlen(s);
    int str_len = 2 * len + 1;
    char* str = (char*)malloc(sizeof(char)*(str_len));
    int *rd = (int*)malloc(sizeof(int)*(str_len)); 
    char* res = (char*)malloc(sizeof(char)*len + 1);
    
    int po = 0, max_len = 0, start = 0, p = 0;
    
    for(int i = 0; i < len; i++)
    {
        str[2*i] = '#';
        str[2 * i + 1] = s[i];
    } 
    str[str_len - 1] = '#';

    rd[0] = 1;

    for(int i = 1; i < str_len; i++)
    {
        rd[i] = i < p ? min(rd[2 * po - i], p - i) : 1;
        while(i + rd[i] < str_len &&  i - rd[i] >= 0 && str[i+rd[i]] == str[i-rd[i]] )
            rd[i]++;
        if(i + rd[i] > p)
        {
            p = i + rd[i];
            po = i;
        }
        
        if(rd[i] - 1 > max_len)
        {
            max_len = rd[i] - 1;
            start = (i - max_len)  / 2;
        } 
    }
    
    
    for(int i = 0; i < max_len; i++)
        {
            res[i] = s[start+i];
        }
        res[max_len] = '\0';
    return res;
}


```

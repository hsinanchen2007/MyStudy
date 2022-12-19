
char * convert(char * s, int numRows){
    int len=strlen(s);
    if (numRows == 1)
        return s;
    char *ret = (char *)malloc(sizeof(char) * (len+1));
    int i=0,k=0,p=0;
    for(i=0;i<numRows;i++){
        k=i;
        while(k<len){
            ret[p]=s[k];
            p++;
            if(i>0&&i<numRows-1&&(k+2*(numRows-i-1)<len)){
                ret[p]=s[k+2*(numRows-i-1)];
                p++;
            }
            k=k+2*(numRows-1);
        }
    }
    ret[len]='\0';
    return ret;
}
![yyy.png](https://pic.leetcode-cn.com/d5255ed51c0ce529c4649a63afea04a943d8ba452860ef821babfc3322fc8bdc-yyy.png)

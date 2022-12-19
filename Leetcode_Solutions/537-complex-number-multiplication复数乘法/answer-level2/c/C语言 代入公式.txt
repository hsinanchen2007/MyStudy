代入公式
![gif.latex.gif](https://pic.leetcode-cn.com/0cfcc19adaabd743b18fceacc2c185725d12b7f89460e66c459905a104d8bd25-gif.latex.gif)

```
char * complexNumberMultiply(char * x, char * y){
    int a, b ,c ,d;
    char *ret = malloc(sizeof(char)*13);
    
    a = b = c = d = 0;
    
    sscanf(x, "%d+%d", &a, &b);
    sscanf(y, "%d+%d", &c, &d);
    
    sprintf(ret,"%d+%di",(a*c-b*d),(a*d+b*c));
    return ret;
}

```
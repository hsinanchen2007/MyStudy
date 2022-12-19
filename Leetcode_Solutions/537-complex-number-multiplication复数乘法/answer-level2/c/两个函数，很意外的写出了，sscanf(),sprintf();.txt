```
#define LEN 64
char * complexNumberMultiply(char * a, char * b){
    int x1,y1;
    int x2,y2,sk1 = 1,sk2 = 1;
    int x = 0, y = 0;
    int p_ri = 0, t_ri = 0, ri = 0;
    char pre[LEN], tail[LEN];
    char *arr = (char *)malloc(sizeof(char) * LEN);
    sscanf(a,"%d+%d",&x1,&y1);//这个把字符转换到数字
    sscanf(b,"%d+%d",&x2,&y2);
    x = x1 * x2 - y1 * y2;//公式计算
    y = y1 * x2 + x1 * y2;
    sprintf(arr,"%d+%di",x,y);//输入数组
    return arr;
}
```

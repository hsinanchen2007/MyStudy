### 解题思路
思路比较简单，反复乘2，大于1则将1减掉，字符串中加入1，否则为加入0，若一直不能变为0，则说明无法表示
![image.png](https://pic.leetcode-cn.com/c76c5c6c7b5b4e159a975ffef4fddfd215533ed08d60f38b60535d6092c597f0-image.png)


### 代码

```c
char str[35];
char* printBin(double num){
    char *p="ERROR";
    if(num>=1||num<0) return p;
    double t=num;
    int i=2;
    str[0]='0',str[1]='.';
    while(t>1e-8){
        if(i>34) return p;
        t*=2;
        if(t>=1){
            t-=1;
            str[i++]='1';
        }
        else str[i++]='0';
    }
    str[i]='\0';
    return str;
}
```
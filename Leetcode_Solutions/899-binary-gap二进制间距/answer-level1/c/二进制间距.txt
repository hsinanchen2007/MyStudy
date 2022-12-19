### 解题思路
根据10进制转化成2进制的方法依次判断每一个余数是否为1，再判断是否是第一个1，根据判断考虑是否要先用i替换j；用三目运算得到最大的两个连续1距离。

### 代码

```c
int binaryGap(int N){
    int a=N,b[100];
    int i=0,j=-1,max=0;
    const int C=2;
    while(a!=0){
        b[i]=a%C;
        a=a/C;
        if(b[i]==1){
        if(j==-1)
        j=i;
        max=(max>(i-j))?max:i-j;
        j=i;
        
        }
        ++i;
        }
        
        
return max;

}
```
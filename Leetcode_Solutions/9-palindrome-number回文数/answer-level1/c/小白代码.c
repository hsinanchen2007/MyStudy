### 解题思路
只比较数字的前半部分和后半部分，所以绝对不会溢出

### 代码

```c
bool isPalindrome(int x){
    if(x<0) return false;//负数直接返回
    int res=0;//用来存储后n位数
    int y=x;
    int count = 0;//存储总共有多少位数
    double k=x;
    int i=1;

    while(k>=1) {k/=10.0; count++;}//将x转换成0.xxx的小数
    while(i<=count/2){
        res = 10*res+y%10;//取出后n位数
        y /=10;
        k*=10.0;//结合下一步取除前n位数
        if((int)k!=res) return false;
        i++;
    }
    return(true);

}
```
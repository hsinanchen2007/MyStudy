思路：
1、求出整数x有多少位。
2、遍历整数x的每一位，再乘上相应的权重并赋值给sum。
3、溢出判断

算法分析
时间 0ms或8ms   空间7MB左右

在求任意位上的值时
 t = tmp/(int)(pow(10,j-1)+0.5)%10; 
加0.5是因为浮点数表示的值并不是确定，比如100用浮点数表示可能为99.999......所以要加个0.5再转换为int型。


```
#define MIN -2147483648
#define MAX 2147483647

int reverse(int x){
    int j, t, i = 0;
    long int tmp = x, sum = 0;
    while(tmp)
    {
        tmp = tmp/10;
        i++;    //计算x的位数
    }
    tmp = x;
    for(j = 1; j <= i; j++)
    {
        t = tmp/(int)(pow(10,j-1)+0.5)%10; //计算x第j位的值
        if(t==0 && j==1)    //第一位为0的情况
            continue;
        sum += t*(long int)(pow(10,i-j)+0.5);
    }
    if(sum<=MAX && sum>=MIN)    //溢出判断
        return sum;
    else
        return 0;
}


```
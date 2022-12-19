### 解题思路
简单来说我的思路就是：从最高位开始，逐位递减到最低位，再将最低位作为最高位逐级返回
emmm，说的不是很明确，具体思路见代码注释：

### 代码

```c
int reverse(int x){
    int i,j,k,l=0,m,result;

    if(x>0&&x-1<pow(2,31)-1)
        k=x;
    else if(x<0&&x+1>-pow(2,31)+1)          
        k=-x;                               //首先判断输入的x是否越界
    else return 0;                          //没有越界则统一转化为正数，后续操作就可统一
                                            

    for(i=0;i>=0;i++){
        j=k/10;

        if(k%10==0) l++;
        else if(k/10>=1) l=0;               //统计两个非零位之间存在多少个零，防止跳过零位

        if(j==0){
            j=(k%10)*pow(10,i);             //找到最高位则将最高位后面的各位清零
            break;
        }else
            k=k/10;
    }
    m=k%10;                                 //保留最高位的值
    k=abs(x)-j;                             //将最高位清零
    if(k==0){
        return (x>0)?m:(-m);                //如果已到最末位，则返回，同时判断x的正负，以满足只有一位的情况
    }
    else if(reverse(k)<=pow(2,31)/pow(10,l+1)&&reverse(k)!=0){

        result=reverse(k)*pow(10,l+1)+m;    //判断结果是否会越界
        return (x>0)?result:(-result);      //没有越界则将返回值进位，并在末位加上当前的最高位

    }else return 0;                         //越界则返回0
        
}
```
### 解题思路
(1) 计算数字位数
(2) 如果位数为0或者为1，输出
(3) 分离出各个位数
(4) 相加
(5) 对加得的数递归处理，直到位数为0或者1

### 代码

```c
int addDigits(int num){
    int n=0,a[10],i=0,j,sum=0;
    while(num>=pow(10,n)){
        n++;
    }
    if(n==1||n==0) return num;
    a[n-1]=num/pow(10,n-1);
    for(i=0;i<n-1;i++){
        a[i]=num%10;
        num=num/10;
    }
    for(i=0;i<n;i++){
        sum=sum+a[i];
    }
    return addDigits(sum);

}





```
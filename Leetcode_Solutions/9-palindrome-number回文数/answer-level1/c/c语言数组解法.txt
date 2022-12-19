### 解题思路
先将x存入数组a中，正序逆序分别输出，两数相等且大于0即为true。还是挺麻烦的。

### 代码

```c
bool isPalindrome(int x){
    int i,j=0,xlength=0,xnumber=0,sign=0;
    int sum1=0,sum2=0;//sum1为正序输出，sum2为逆序输出
    int *a;//开辟数组
    xnumber=x;
    sign=x;
    while(xnumber!=0){//计算x的位数
        xnumber=xnumber/10;
        xlength++;
    }
    a=(int *)malloc(xlength*sizeof(int));//开辟数组
    for(i=0;i<xlength;i++){//数组存x
        a[i]=x%10;
        x=x/10;
    }
    for(i=0;i<xlength;i++){//正序输出
        sum1=sum1+a[i]*pow(10,i);
    }
    for(i=xlength-1;i>=0;i--){//逆序输出
        sum2=sum2+a[i]*pow(10,j++);//**不是i是j**
    }
    if(sum1==sum2&&sign>=0)
        return true;
    else
        return false;
}
```
### 解题思路
（1）处理特殊或简单情况
（2）利用辗转相除法求取最大公约数
（3）看z是否能整除最大公约数

### 代码

```c
bool canMeasureWater(int x, int y, int z){
    int min,max,i;
    int gcd(int x,int y);
    if(z==0) return true;
    if(z>(x+y)) return false;
    if(z==x+y||z==x||z==y) return true;
    min=x>y?y:x;
    max=x>y?x:y;
    if(min==0&&z!=max-min) return false;
    if(z==max-min) return true;
    /*for(i=min;i>0;i--){
        if(min%i==0&&max%i==0) break;
    }*/
    i=gcd(max,min);
    if(z%i==0) return true;
    else return false;

}

int gcd(int x,int y){
    int r;
    while(y>0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
```
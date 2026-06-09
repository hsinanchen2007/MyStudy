### 解题思路
将最高位的6替换成9，等于是原数加3乘以10的位数次幂。
循环遍历num的每一位，因为是从低位到高位，每次都更新10的幂次方(ad)，如果当前位数数字<9,则记录在该位替换应该加的10的幂次方数(maxx)，最后返回num+3*maxx

### 代码

```c
int maximum69Number (int num){
    int i=0;
    int ad;
    int base=num;
    int maxx;
    while(num>0){
        i++; 
        if (i==1){
            ad=1;
        }else {
            ad=ad*10;
        }       
        if (num%10 < 9){
            maxx=ad;
        }
        num /=10;
    }    
    return base+3*maxx;
    
}
```
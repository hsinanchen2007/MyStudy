### 解题思路
递归出口条件：各位和小于10时（为单数）直接输出
递归操作：计算num的各位和

### 代码

```c
int addDigits(int num){
    if(num<10) return num;
    int ans=0;
    while(num!=0){
        ans+=num%10;
        num/=10;
    }
    return ans<10?ans:addDigits(ans);

}
```
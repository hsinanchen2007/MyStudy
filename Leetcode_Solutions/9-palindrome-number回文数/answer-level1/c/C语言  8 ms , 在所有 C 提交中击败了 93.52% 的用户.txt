### 解题思路
先定义一个变量用于存储和最高位相等的整数，比如3553则div为3000，判断左右两位是否相等后，利用数学计算先把最高位*div ，再用(x-left*div-right)/10；纯数学计算，可以找张白纸凑一凑就出来了，将首尾两位去掉，刚开始将while中x判断条件为x>9，就想中间一位就不判断了，但是遇到100021这种数就会判断成true，将while条件改为x！=0,利用x/div就可以判断出来中间有0的情况。

### 代码

```c
bool isPalindrome(int x){
    if (x<0) return false;
    int div=1;
    while(x/div>=10) div*=10;//找到离x最近的整十整百整千数
    while(x!=0){
        int left=x/div; //取最左面的一位数
        int right=x%10; //取最右面的一位数
        if(left!=right)
        return false;
       else{
           x=(x-left*div-right)/10;
            div=div/100;
            } 
            
    }
    return true;
}
```
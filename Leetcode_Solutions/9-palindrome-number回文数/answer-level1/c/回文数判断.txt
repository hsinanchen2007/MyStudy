### 解题思路
思路是：
1.先求出数的位数
2.将两边的数比较，比较完去掉两边的数，知道最后只剩一位或0位，得出x为回文数

### 代码

```c
bool isPalindrome(int x){
    if(x<0)return false;
    int num = 1,temp=x;
    while(temp/=10)num++;
    while(1){
        if(num<2)return true;
        int temp = (int)pow(10,num-1);
        if(x/temp==x%10){
            x%=temp;
            x/=10;
            num-=2;
        }else return false;
    }
    return false;
}
```
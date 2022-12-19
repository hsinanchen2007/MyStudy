### 解题思路
利用递归，不断地判断cnt的值是否为一位数。
### 代码

```c
int addDigits(int num){
    int cnt=0;
    while(num)
    {
        cnt=cnt+num%10;
        num/=10;
    }
    if(cnt/10)
    {
        cnt=addDigits(cnt);
    }
    else
    {
        return cnt;
    }
    return cnt;
}
```
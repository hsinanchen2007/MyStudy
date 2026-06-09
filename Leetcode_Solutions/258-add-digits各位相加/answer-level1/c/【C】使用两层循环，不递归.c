### 解题思路
此处撰写解题思路

### 代码

```c
int addDigits(int num){
    int res=0;
    while(num>=10)
    {
        while(num)
        {
            res=res+num%10;
            num/=10;
        }
        num=res;
        res=0;
    }

    return num;

}
```
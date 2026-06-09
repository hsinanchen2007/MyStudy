### 解题思路


### 代码

```c
int countNumbersWithUniqueDigits(int n){
    int result=0;
    for(;n>=0;n--)
    {
        result +=count(n);
    }
    return result;


}
int count(int m)
{
    int result=9;
    if(m==0)
        return 1;
    else if(m==1)
        return 9;
    else if(m>=11)
        return 0;
    else {
        for(;m>1;m--)
        {
            result= result*(11-m);
        }
        return result;
    }
}
```
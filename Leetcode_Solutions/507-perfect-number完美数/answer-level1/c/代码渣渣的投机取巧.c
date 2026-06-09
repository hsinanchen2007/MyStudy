### 解题思路
此处撰写解题思路

### 代码

```c
int addresult(int a,int b)
{
    return a+b;
}

bool checkPerfectNumber(int num){
    int process = 0;
    for (int i = 1;i <= num/2;i++)
    {
        if (num%i == 0)
        {
            process = addresult(process,i);
        }
    }
    return process == num && num > 0;
}
```
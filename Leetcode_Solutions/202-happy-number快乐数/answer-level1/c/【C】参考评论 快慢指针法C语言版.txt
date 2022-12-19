### 解题思路
此处撰写解题思路

### 代码

```c
int squareSum(int m);

bool isHappy(int n){
    int fast=n;
    int slow=n;
    do
    {
        slow=squareSum(slow);
        fast=squareSum(fast);
        fast=squareSum(fast);
    }while(slow!=fast);
    if(fast==1)
        return true;
    else
        return false;
}

int squareSum(int m)
{
    int squaresum=0;
    while(m!=0)
    {
        squaresum+=(m%10)*(m%10);
        m/=10;        
    }
    return squaresum;
}
```
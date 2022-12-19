### 解题思路
与操作

### 代码

```c
int hammingDistance(int x, int y)
{
    int i;
    int s=0;
    for(i=0;i<31;i++)
    {
        if((x&(1<<i))==(y&(1<<i)))
        {
            
        }
        else
        {
            s++;
        }
    }
    return s;
}
```
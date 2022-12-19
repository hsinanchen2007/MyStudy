### 解题思路
一个星期的小白暴力破解之路，算出来各个位数，如果位数为0，则这个数肯定不是，如果余数不为0也肯定不是，符合条件h运行到最后的数才是。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize){

int (*p) = (int *) malloc(sizeof(int)*(right - left + 1));
int num , k = 0;

for ( num = left; num <= right ; num++)
{
    int temp = num;
    while(temp)
    {
        int fig = temp % 10;
        if(fig == 0)
        {
            break;
        }
        if (num % fig != 0)
        {
            break;
        }
        temp =temp / 10;
    }

    if (temp == 0 )
    {
        p[k] = num;
        k++;
    }
}
*returnSize = k;
return p;
}
```
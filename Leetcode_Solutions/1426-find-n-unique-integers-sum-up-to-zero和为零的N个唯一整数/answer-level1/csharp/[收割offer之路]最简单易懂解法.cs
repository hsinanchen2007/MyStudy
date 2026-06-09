依次加入0到n-1 , 最后一个数加入 负的前n-1个数的和
```
public int[] SumZero(int n)
{
    int[] res = new int[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            sum += i;
            res[i] = i;
        }
        else
        {
            res[i] = -sum;
        }
    }
    return res;
}
```

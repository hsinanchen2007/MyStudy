从最接近平方根的位置求解。
PS:一开始是从1开始遍历，而且还没注意只要遍历到平方根就OK了，遍历到了num+n/2，结束了才想起来。
```
    public static int[] ClosestDivisors(int num)
        {
            int[] min= { 1, num + 1 };

             for (int i = (int)MathF.Sqrt(num + 1); i >= 1; i--)
            {
                if ((num + 1) % i == 0)
                {

                     if(min[1]-min[0] > (num + 1) / i-i)
                     {
                         min[0] = i;
                         min[1] = (num + 1) / i;
                        break;
                     }
                }
            }

            for (int i = (int)MathF.Sqrt(num + 2); i >= 1; i--)

            {
                if ((num + 2) % i == 0)
                {
                    if (min[1] - min[0] > (num + 2) / i - i)
                    {
                        min[0] = i;
                        min[1] = (num + 2) / i;
                        break;
                    }
                }
            }
            return min;
        }
```

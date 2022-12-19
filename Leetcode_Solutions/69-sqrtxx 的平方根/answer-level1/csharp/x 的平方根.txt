**思路1：** 无脑调用现成实现
```
 public int MySqrt(int x)
        {
            return (int)Math.Sqrt(x);
        }
```
**思路2：** 二分查找1, left, right都声明为double，mid*mid=x直接返回，或者(int)left == (double)right退出循环。（此写法代码略冗长）
```
public int MySqrt2(int x)
        {
            double left = 0;
            double right = x;
            while (left <= right)
            {
                double mid = (left + right) / 2;
                var tempResult = mid * mid;
                if (tempResult == x)
                {
                    return (int)mid;
                }
                else if (tempResult > x)
                {
                    right = mid;
                }
                else
                {
                    left = mid;
                }

                //如果left和right的整数位相等则退出循环
                if ((int)left == (int)right)
                {
                    break;
                }
            }

            return (int)left;
        }
```
**思路3：** 二分查找2，left，right均声明为长整型
```
public int MySqrt3(int x)
        {
            long left = 0;
            long right = x;
            while (left < right)
            {
                long mid = (right + left + 1) / 2;
                long tempResult = mid * mid;

                if (tempResult > x)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid;
                }
            }

            return (int)left;
        }
```

**思路：** 直接计算每位平方和，出现1就返回true，出现重复的sum就直接返回false（退出循环的条件不是非常容易想到）。
```
public bool IsHappy(int n)
        {
            var sum = 0;
            var set = new HashSet<int>();

            while (sum != 1)
            {
                sum = 0;
                while (n > 0)
                {
                    sum = sum + (int)Math.Pow(n % 10, 2);
                    n = n / 10;
                }
                //如果set中包含了sum，则会进入死循环即不可能存在解
                if (set.Contains(sum))
                {
                    return false;
                }
                set.Add(sum);
                n = sum;
            }

            return true;
        }
```

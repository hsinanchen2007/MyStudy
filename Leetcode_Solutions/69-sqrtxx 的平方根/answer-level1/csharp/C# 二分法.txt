用 mid==x/mid 而不是 mid*mid==x 防止数值溢出
```C# []

public class Solution {
 
      public  int MySqrt(int x)
        {
            if (x == 0) return 0;
            int left = 1, right = x, mid = (left+right)/2;
            while(left<right&&mid!=left)
            {
                if(mid== x/mid)
                {
                    return mid;
                }else if(mid < x / mid)
                {
                    left = mid;
                    mid = (left + right) / 2;
                }
                else
                {
                    right = mid;
                    mid = (left + right) / 2;
                }
            }
                return left;
        }
}
```
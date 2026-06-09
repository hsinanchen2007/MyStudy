
```
public class Solution {
        public double MyPow(double x, int n)
        {
            if (n < 0)
            {
                x = 1 / x;
                n = -n;
            }

            return _MyPow(x, n);
        }

        private double _MyPow(double x, int n)
        {
            if (n == 0) return 1.0;
            double half = _MyPow(x, n / 2);
            if (n % 2 == 0) return half * half;
            return half * half * x;
        }
}
```
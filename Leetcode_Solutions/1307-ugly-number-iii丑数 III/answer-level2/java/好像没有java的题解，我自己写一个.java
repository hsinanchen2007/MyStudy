```
class Solution {
    public int nthUglyNumber(int n, int a, int b, int c) 
    {
        int bt1 = nthUglyNumberFz(n,a,b,c);
        if (bt1 != -1)
        {
            return bt1;
        }
        int bt2 = nthUglyNumberFz(n,b,a,c);
        if (bt2 != -1)
        {
            return bt2;
        }
        return nthUglyNumberFz(n,c,b,a);
        
    }
    public int nthUglyNumberFz(int n, int a, int b, int c)
    {
        int l = 1;
        int r = Math.min(a,Math.min(b,c)) * n / a;
        while (l <= r)
        {
            if(getNum(l * a,a,b,c) == n)
            {
                return l * a;
            }
            if(getNum(r * a,a,b,c) == n)
            {
                return r * a;
            }
            int mid = l + (r - l) /2;
            if(getNum(mid * a,a,b,c) == n)
            {
                return mid * a;
            }
            if (getNum(mid * a,a,b,c) < n)
            {
                l = mid + 1;
                r--;
            }
            else
            {
                r = mid -1;
                l++;
            }
        }
        return -1;
    }
    public int getNum(int n,int a,int b,int c)
    {
        int a1 = (int) (n /(getMaxGb(a,b)));
        int a2 = (int) (n /(getMaxGb(a,c)));
        int a3 = (int) (n /(getMaxGb(c,b)));
        int a4 = (int) (n /(getMaxGb(getMaxGb(a,b),c)));
        return n / a + n / b + n / c + a4 - a1 - a2 - a3;
    }
    public long getMaxGb(long a,long b)
    {
        if (b > a)
        {
            return getMaxGb(b,a);
        }
        long sum = a * b;
        while (b != 0)
        {
            long temp = a % b;
            a = b;
            b = temp;
        }
        return sum / a;
    }
}
```

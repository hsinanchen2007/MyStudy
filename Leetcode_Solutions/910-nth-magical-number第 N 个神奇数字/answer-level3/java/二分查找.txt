难点在于排除掉最小公倍数的公共部分，然后控制循环条件确保得到的是精确值
```java
class Solution {
	  public int nthMagicalNumber(int N, int A, int B) {
	       long lcm = (A*B)/gcd(A,B);
	       long mod = (long)1e9 + 7;
	       long left = 2;
	       long right = (long)1e14;
	        while (left < right) {
	            long mid = (left + right) / 2;
                    //这个循环并没有判断 == N就输出，而是>=N一直令right减少到left,left是刚好能使小于号不成立的最小值，同时也是等号成立的最小值。此时得到的就是精确解。
	            if (mid / A + mid / B - mid / (A * B / lcm) < N) left = mid + 1;
	            else right = mid;
	        }
	        return (int)(left % mod);
	    }
	  long gcd(long a, long b) {
		  if(b == 0)return a;
		  else
			  return gcd(b,a % b);
	  }
}
```
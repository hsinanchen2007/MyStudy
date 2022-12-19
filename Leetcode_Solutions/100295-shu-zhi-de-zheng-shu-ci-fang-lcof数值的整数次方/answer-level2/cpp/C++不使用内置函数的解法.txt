### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
		if (x == 0)return 0;
		if (n == 0)return 1;
		double res = 1; 
		long long absn = n>0?(long long)n:(long long)-1*n;
		while (absn >= 2) {
			long long con = 1;
			double Rres = 1;
			while (absn >= con * 2) {
				con *= 2;
				if (con == 2) {
					Rres = Rres*x*x;
				}
				else {
					Rres = Rres*Rres;
				}
			}
			absn = absn - con;
			res = res*Rres;
		}
		if (absn == 1) res = res*x;
		if (n < 0)res = 1 / res;
		return res;
    }
};
```
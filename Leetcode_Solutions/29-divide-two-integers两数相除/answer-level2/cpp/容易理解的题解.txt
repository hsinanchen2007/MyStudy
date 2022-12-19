- idea：
 	1.	令div_cur初始化为除数，令倍数cur_mul初始化为1，并令剩余remain初始化为被除数。
 	2.	假如remain>=div_cur,说明被除数至少是除数的cur_mul倍，因此ans+=cur_mul
 	3.	每次递增减去的数div_cur，且递增对应的倍数cur_mul
 	4.	当remain<div_cur时，令div_cur和cur_mul重新初始化
 	5.	有各种特殊情况。如divisor==0时应该返回-1
 	6.	由于将除数与被除数都转为了正数，因此最大负值有可能会溢出，因此要对最大负值进行特殊处理。
 	7.	当除数==INT_MIN，而被除数不等于INT_MIN，则返回0
 	8.	当除数、被除数都等于INT_MIN，则返回1
 	9.	当被除数等于INT_MIN，而除数不等于INT_MIN时，需要将被除数改成正数，会溢出，此时可以递归处理，利用**除法分配式**。同时考虑到加上某个数以后可能会出现四舍五入，因此要加的数应该为div_init自身。


- code

		#include <bits/stdc++.h>
		
		using namespace std;
		
		class Solution {
		public:
			int divide(int dividend, int divisor) {
				if (dividend == INT_MIN && divisor == -1)	return INT_MAX;
		
				if (divisor == 0)	return -1;
		
				if (divisor == INT_MIN && dividend != INT_MIN)	return 0;
		
				if (divisor == dividend)	return 1;
		
				int ans = 0;
		
				int cur_mul = 1;
		
				int div_cur = (divisor>0 ? divisor : -divisor), div_init = (divisor>0 ? divisor : -divisor);
				

				//除法分配式
				if (dividend == INT_MIN){
					return divide(dividend + div_init, divisor) - divide(div_init, divisor);
				}
		
				int remain = (dividend>0?dividend:-dividend);
		
				int flag = ((dividend^divisor) < 0);
		
				while (remain >= div_init) {
					ans += cur_mul;
					remain -= div_cur;
		
					if (INT_MAX - div_cur > div_cur) {
						div_cur += div_cur;
						cur_mul += cur_mul;
					}
		
					if (remain < div_cur) {
						div_cur = div_init;
						cur_mul = 1;
					}
				}
		
				return flag>0?-ans:ans;
			}
		};
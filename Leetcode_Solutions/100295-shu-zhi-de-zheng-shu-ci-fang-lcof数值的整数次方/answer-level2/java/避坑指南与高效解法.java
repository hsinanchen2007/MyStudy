### 执行结果
用时：1ms,在java提交中击败了90.14%的用户
内存：38.1MB，在java提交中击败了100%的用户
### 注意
- 需要将n转换为long型；
- 用左移代替除法，有助于提高效率；
- 用位与运算代替求余，有助于提高效率；
### 解题思路
![image.png](https://pic.leetcode-cn.com/ab1b61f23502a96d9e45939a652b8e57fdb3bb6c2e6e6e8869f630f6874030e0-image.png)
例如求某数的32次方：
1. 先求平方，在平方的基础上求4次方；
2. 在4次方基础上求8次方；
3. 在8次方基础上求16次方；
4. 在16次方基础上求32次方；

### 代码

```java
class Solution {
    public double myPow(double x, int n) {
       double res;
		long N=n;
		if(Equal(x, 0.0)||Equal(x, 1.0)) {
			return x;
		}
		if(N<0) {
			long absN=-N;
			res=PowerWithUnsignedExponent(x, absN);
			res=1/res;
		}else {
			res=PowerWithUnsignedExponent(x, N);
		}
		return res;
    }
    public static double PowerWithUnsignedExponent(double base,long exponent) {
		if(exponent==0) {
			return 1;
		}
		if(exponent==1) {
			return base;
		}
		double res=1;
		res=PowerWithUnsignedExponent(base, exponent>>1);
		res*=res;
		if((exponent & 1)==1) {
			res=base*res;
		}
		
		return res;
	}
	public static boolean Equal(double num1,double num2) {
		if(((num1-num2)>-0.0000001)&&
				((num1-num2)<0.0000001)) {
			return true;
		}else {
			return false;
		}
	}
}
```
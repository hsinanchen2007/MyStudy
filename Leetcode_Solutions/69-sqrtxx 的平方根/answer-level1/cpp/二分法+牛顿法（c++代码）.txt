# 题目描述
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。

# 题目解析
因为x的平方根一定在[0,x]之间，所以我们只需要找到这样`res,res^2 <= x,res^2>x`即可。搜索方法有很多，此处采用[二分法模板](https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/),具体思路就不在此赘述。除此之外，还可以采用比较经典的牛顿法求解，设解为a，原方程可等价为`f(a) = a^2 -x`，求出a即可。
# 思路1
二分法搜索[0,x]，找到满足条件的res返回。
# 代码
```
class Solution {
public:
    int mySqrt(int x) {
        long left = 0,right = x;//防止溢出问题，用long存储int
        long mid;
        while(left < right)
        {
            mid = left + (right - left + 1)/2;
            if(mid > x/mid)//注意不可写成mid*mid，存在溢出问题
            {
                right = mid - 1;
            }
            else{
                left = mid;
            }
        }
        return left;
    }
};

```

# 思路2
牛顿法求解方程`f(a) =a^2 -x `，按照牛顿法的思路推导后，可得迭代公式`a0=1/2 x (a + x/a) `。
# 代码
```
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)return 0;
	    double a0 = x;
    	double a = 0;
    	while (abs(a0 - a) >= 0.00001)//精度
        {
		a = a0;
		a0 = (a0 * a0 + x) / (2 * a0);
	    }
	return int(a);
    }
};
```
收敛速度很快，用时0ms。

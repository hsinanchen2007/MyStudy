### 解题思路
此处撰写解题思路
重点还是边界，Java 的边界搞死我
### 代码

```cpp
class Solution {
public:
    double myPow(double x,int n){
    long b=n;
    if(n==0)
    return 1;
    if(n<0)
    return myPow2(1/x,-b);
    else
    return myPow2(x,n);
    } 
    double myPow2(double x, long n) {
    long b=n;
	if(b<0)
	{
    return myPow(1/x,-b);
	}
	else
	{	
	if(b%2==0)
	return myPow(x*x,b/2);
	else
	return myPow(x*x,(b-1)/2)*x;
	}
    }
};
```
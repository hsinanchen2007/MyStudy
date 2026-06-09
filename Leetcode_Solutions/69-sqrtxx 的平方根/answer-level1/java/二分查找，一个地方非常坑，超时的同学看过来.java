### 解题思路
    其实本质上就是查找，所有查找的方法都可以用，区别在于时间和空间复杂度不同，其中一个非常坑的地方就是如果将遍历的变量定义为int的话，会超时，要声明称long类型，最后再强制类型转换即可。

### 代码

```java
class Solution {
    public int mySqrt(int x) {
         long  low=0;
	    long high=x;
	    long mid=0;
	    while(low<=high)
	    {
	    	mid=(low+high)/2;
	    	if(mid*mid==x||mid*mid<x&&(mid+1)*(mid+1)>x)
	    		return (int)mid;
	    	if(mid*mid>x)
	    	{
	    		high=mid-1;
	    	}
	    	else 
	    	{
	    		low=mid+1;
	    	}
	    }
		  return (int)mid;
    }
}
```
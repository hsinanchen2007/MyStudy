### 解题思路
   这应该算是非常常规的题目，从个位开始，逐位处理，对10取余来取最后一位，除以10去掉最后一位。

### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
         int sum=0;
	     int pro=1;
	     int num=n;
	     while(num>=10)
	     {
	    	 sum+=num%10;
	    	 pro*=num%10;
	    	 num/=10;
	     }
	     sum+=num;
	     pro*=num;
	     return pro-sum;
	     
    }
}
```
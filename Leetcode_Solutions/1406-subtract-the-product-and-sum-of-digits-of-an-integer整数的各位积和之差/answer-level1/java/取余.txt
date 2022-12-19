### 解题思路
各位相乘减去各位相加

### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
		if(n==0)
		{
			return 0;
		}
		int num = 0;
		int product = 1;
        while(n!=0)
        {
        	int a = n%10;
        	num+=a;
        	product*=a;
            n/=10;
        }
        return product-num;
    }
}
```
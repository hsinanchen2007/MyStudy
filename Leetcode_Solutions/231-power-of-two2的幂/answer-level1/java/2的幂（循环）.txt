这个解法中特殊的地方就在于所有2的幂次方，要么等于i*i,要么等于i*i/2。之前的判断是为了快速排除干扰项，余二不为0肯定不是，6余二为0但除数为三，所以余三为0 的也不是

	
```java
public boolean isPowerOfTwo(int n){
		if(n==1)
			return true;		
		if(n%2 != 0||n%3==0)
			return false;
		int i = 2;
		while(i*i<n){
			i=(i*2);
		}
		if(i*i==n||i*(i/2)==n)
			return true;
		return false;
	}
```

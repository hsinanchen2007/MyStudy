### 解题思路
![1.png](https://pic.leetcode-cn.com/7004b69259c4b5b5fb434edcc3353366649b77a969c2c115adea36e99422f7d8-1.png)
算法很简单，就是通过取余取除，取到各个位置的数，然后通过*10来挪位。

### 代码

```c
int reverse(int x){
    int mod = 0;
    long y = 0;
    int i = 0;
	int MAX = 2147483646;
	int MIN = -2147483647;

	if((x < MIN) || (x > MAX))
	{
        return 0;
	}

    while(x != 0) {
        mod = x % 10;
        x = (int)(x / 10);
		if(((y*10 + mod) < MIN) || ((y*10 + mod) > MAX)) {
		    return 0;
		}

        y = y * 10 + mod;
    }

	return y;
}
```
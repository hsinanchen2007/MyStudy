解题思路清晰易懂，小白的成长之路

### 代码

```java
class Solution {
    public int reverse(int x) {
        if(x == Integer.MIN_VALUE)
			return 0;
		
		int flag = 1;
		if(x < 0)
			flag = -flag; //-1
			x = x * flag;
		
		int res = 0;
		while(x > 0){ // 输入:1534236469
			int n = res;
			n *= 10;
			n += x % 10;	
			x /= 10;
			if(n / 10 != res){ //这一步很关键，判断*10左移一位后是否溢出
				return 0;
			}
			res = n;
		}
		return (flag > 0)? res : res*flag;
    }
}
```
![image.png](https://pic.leetcode-cn.com/6e1f6ec38cf085b0a50a60d8b890efdb837459e7faad27b38ab731b51b8b9933-image.png)

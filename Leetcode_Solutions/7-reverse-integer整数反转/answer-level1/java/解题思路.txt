### 解题思路
###此处撰写解题思路
###运算比较简单，关键是一定要注意溢出操作。

### 代码

```java
class Solution {
   public static int reverse(int num) {
		int rev = 0;
		while(num!=0) {
			int revnew = rev*10+num%10;
			if((revnew - num % 10) / 10 != rev){ //最关键的一步
                return 0 ;
            }
             rev = revnew;
			 num = num/10;
		}
		
		return rev;
	}
}
```
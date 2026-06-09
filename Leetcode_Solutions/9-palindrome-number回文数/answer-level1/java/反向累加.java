### 解题思路
反向累加

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        int reverse=0;
        int y=x;
    	while(y!=0) {
        	reverse=reverse*10+y%10;
        	y/=10;
        }
    	if (reverse>=0&&reverse==x) {
			return true;
		}else {
			return false;
		}

    }
}
```
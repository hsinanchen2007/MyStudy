### 解题思路
我的想法是用数组来存储数的每一位，然后再从数组两端开始比较，看是否相等，不相等就不是回文数

### 代码

java
class Solution {
    public boolean isPalindrome(int x) {
    	if (x >= 0) {
	    	int [] a = new int [20];
	    	int num = 0, cnt = x;
	    	while (cnt != 0) {
	    		a[num] = cnt%10;
	    		num++;
	    		cnt /= 10;
	    	}
	    	num -= 1;
	    	for (int i = 0; i < num; ) {
				if (a[i++] != a[num--]) return false;
			}
	    	return true;
    	}
    	else return false;
    }
}
```
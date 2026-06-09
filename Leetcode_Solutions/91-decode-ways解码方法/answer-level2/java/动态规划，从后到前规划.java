### 解题思路
画下图，从长度为2的画到长度为4的，找下规律，先别考虑有0的问题，然后你会发现每在左边加入一个非0节点就相当于在
原本长度的基础上加了一个，和在原本长度-1的基础上（要判断新加入的和原最左边的加在一起是否合法，在1-26中）又加了一个。然后就得出来了

### 代码

```java
class Solution {

	public int numDecodings(String s) {
		if (s.charAt(0) == '0') {
			return 0;
		}
		int len = s.length();
		int[] times = new int[len];
		if (isValid(s.substring(len - 1, len))) {
			times[len - 1] = 1;
		}
		if (len>=2&&times[len-1]==1&&isValid(s.substring(len - 2, len - 1) )) {
			times[len - 2] = 1;
		}
		if (len>=2&&isValid(s.substring(len - 2, len))) {
			times[len - 2] += 1;
		}
		int k = len - 3;
		while (k >= 0) {
			if (s.charAt(k) == 0) {
				k--;
				continue;
			}
			if(isValid(s.substring(k,k+1)))
			   times[k] = times[k]+times[k + 1];
			if(isValid(s.substring(k,k+2)))
				times[k] = times[k]+times[k + 2];
			k--;

		}

		return times[0];
	}
    public boolean isValid(String s) {
		if (s.length() > 2 || s.length() < 1 || s.charAt(0) == '0')
			return false;
		else {
			Integer i = new Integer(s);
			if (i > 0 && i <= 26)
				return true;
		}
		return false;
	}

}
```
### 解题思路
two keypoints:
1. as long as unsigned result is bigger than Integer.MAX_VALUE, it can be regarded as overflow.
2. examine the edge condition before the multiplication to avoid overflow.

two improvement:
1. trim() cost so simulating by hand
2. division cost so pre-calculating the constant
### 代码

```java
class Solution {
    public int strToInt(String str) {
        int result = 0;
        int sign = 1;
        boolean overflow = false;
        int i = 0;
        final int max = Integer.MAX_VALUE / 10;
        final int residue = Math.abs(Integer.MIN_VALUE % 10);
        while(i < str.length() && str.charAt(i) == ' '){
          i ++;
        }
        if(i >= str.length())
        	return 0;
    	char c = str.charAt(i);
    	if(c == '+'){
    		i++;
       	}else if(c == '-'){
    		sign = -1;
    		i++;
    	}else if(!(c <= '9' && c >= '0'))
    	    return 0;

    	while(i < str.length() && ((c = str.charAt(i)) <= '9' && c >= '0' )){
    		int k = c - '0';
    		if((result == max && k >= residue) ||result > max){
    			overflow = true;
    			break;
    		}else 
    		result = result * 10 + k;
    		i++;
    	}
    	if(overflow){
    		if(sign == 1)
    			return Integer.MAX_VALUE;
    		else return Integer.MIN_VALUE;
    	}else {
    		return result * sign;
    	}

    }
}
```
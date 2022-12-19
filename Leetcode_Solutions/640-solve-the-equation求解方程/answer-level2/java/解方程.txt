### 解题思路
分左右，逐个解析出，左x参数leftx,左常数leftnum,以及右边的
然后判断

### 代码

```java
class Solution {
    public String solveEquation(String equation) {
        String[] equal = equation.split("=");
        int[] left = help(equal[0]);
        int[] right = help(equal[1]);
        int x = left[0]-right[0];
        int num = right[1]-left[1];
        if(x == 0) {
        	if(num == 0) {
        		return "Infinite solutions";
        	}else {
        		return "No solution";
        	}
        }else {
        	return "x="+num/x;
        }
    }
	
	public int[] help(String str) {
		int[] ans = new int[2];
		int flag = 1;
        for(int idx = 0 ; idx < str.length(); idx++) {
        	int s = idx;
        	while(idx < str.length() && 
        			str.charAt(idx)!= '-' && 
        					str.charAt(idx)!='+') {
        		idx++;
        	}
            if(s == idx) {
        		flag = -1;
        		continue;
        	}
        	if(str.charAt(idx-1) == 'x') {
        		if(idx-1 == s) {
        			ans[0] += flag;
        		}else {
        			ans[0] += flag * Integer.valueOf(str.substring(s, idx-1));
        		}
        	}else {
        		ans[1] += flag * Integer.valueOf(str.substring(s, idx));
        	}
        	if(idx < str.length()) {
        		if(str.charAt(idx) == '+') {
        			flag = 1;
        		}else {
        			flag = -1;
        		}
        	}
        }
		return ans;
	}
}
```
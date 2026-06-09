![2020010401.PNG](https://pic.leetcode-cn.com/bad01a81fffae3f7b06efe0d5244658d118551fb3fbe10220859bd5089f9560f-2020010401.PNG)
### 解题思路
类似进制转换,1)当余数为0时,当前位置的值置为'z',整除得到的数减1;
2)当余数不为0时,直接替换成相应的字母
### 代码

```java
class Solution {
    public String convertToTitle(int n) {
        String out = "";
    	int resNum = 0;
    	boolean active = false;
    	while(n>=26) {
    		resNum = n%26;
    		if(resNum!=0) {
            	out = (char)(resNum+64)+ out;
            	n = n/26;
    		}else {
    			out = "Z"+ out;
    			active = true;
    			n = n/26-1;
    		}
    	}
    	if(active) {
    		if(n>0) {
    			out = (char)(n+64)+ out;
    		}
    	}else {
        	out = (char)(n+64)+ out;
    	}
        return out;
    }
}
```
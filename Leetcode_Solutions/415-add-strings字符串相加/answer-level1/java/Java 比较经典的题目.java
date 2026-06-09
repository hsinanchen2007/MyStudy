### 解题思路

![IMG_0459.PNG](https://pic.leetcode-cn.com/c4f3d36944c21ecdb1f6aee7cdddbef7c1ef9d45406da16309a1f5447bea960b-IMG_0459.PNG)


### 代码

```java
class Solution {
    public String addStrings(String num1, String num2) {
        StringBuilder result = new StringBuilder();
    	int i = num1.length()-1;
    	int j = num2.length()-1;
    	int carry = 0;
    	while(i>=0 || j>=0) {
    		int n1 = i>=0? num1.charAt(i)-'0':0;
    		int n2 = j>=0? num2.charAt(j)-'0':0;
    		int temp = n1+n2+carry;
            result.append(temp%10);
    		carry = temp/10;
            i--;
    		j--;
    	}
        if(carry==1) result.append(1);
    	return result.reverse().toString();
    }
}
```
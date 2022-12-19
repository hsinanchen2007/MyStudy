### 解题思路
回文字符串存在中心，因此只需要通过中心找两边的字符串就能找到最长的子字符串

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        if(s == null || s.length() <= 1)
        return s;
    	int maxLeft = 0,maxRight = 0, maxLength = 0;
    	for (int i = 0; i < s.length(); i++) {
			int childLenght = expandPalindrome(s, i, i);
			if(childLenght > maxLength) {
				maxLength = childLenght;
				maxLeft = i - maxLength / 2;
				maxRight = i + maxLength/2;
			}
			childLenght = expandPalindrome(s, i, i + 1);
			if(childLenght > maxLength)
			{
				maxLength = childLenght;
				maxLeft = i - maxLength / 2 + 1;
				maxRight = i + maxLength/2;
			}
		}
        return s.length() >= maxRight ? s.substring(maxLeft, maxRight + 1) : s.substring(maxLeft);
    }
    private int expandPalindrome(String s, int left, int right){
    	int iLeft = left;
    	int iRight = right;
    	while (iLeft >= 0 && iRight < s.length() && s.charAt(iLeft) == s.charAt(iRight)) {
    		iLeft --;
    		iRight ++;		
		}
    	
    	return iRight-iLeft -1;
    }
}
```
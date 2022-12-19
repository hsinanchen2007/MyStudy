### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        s=s.trim();
        int i=0;
		for( i=s.length()-1;i>=0;i--){
			if(s.charAt(i)==' ')
				break;
		}
        return s.length()-1-i;
    }
}
```
### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
	public void reverseString(char s[]) {
	      int left=0;
	      int right=s.length-1;
		while(left<right) {
			int temp=s[left];
			s[left]=s[right];
			s[right]=(char) temp;
			left++;
            right--;
		}
	}
}
```
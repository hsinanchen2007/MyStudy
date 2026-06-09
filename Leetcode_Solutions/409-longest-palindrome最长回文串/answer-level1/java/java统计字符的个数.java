### 解题思路
java统计字符的个数，偶数个直接相加，奇数减一再加，最后再加1

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
         char[] a = s.toCharArray();
         int len = 'z'-'A'+1;
		 char[] up = new char[len];
		 
	     int count = 0;
		 for(int i=0;i<a.length;i++){
			up[a[i]-'A']++;
		 }

		 int flag = 0;
		 for(int i=0;i<len;i++){
			 
			 if(up[i] % 2 ==0){
				 count= count + up[i];
			 }else{
                 count= count + up[i]-1;
                 flag = 1;
             }
		 }
		 
		 return count+flag;
    }
}
```
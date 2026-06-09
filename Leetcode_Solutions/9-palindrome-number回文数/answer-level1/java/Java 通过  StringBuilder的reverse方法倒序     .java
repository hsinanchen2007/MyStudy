### 解题思路
将X 转换为Integer对象， 再利用StringBuffer里的reverse方法倒序字符串，

注意比较时必须把StringBuffer对象转成String，使用String的equals方法进行字符串的比较，因为StringBuffer里的equals方法并没有重写Object里的equals方法，并不能比较字符串的值是否相等。

### 代码

```java
class Solution {
 public  boolean isPalindrome(int x ) {
		
		
		 if(x<0) {
			 return false;
		 }
		Integer itg = new Integer(x);
		String s1= itg.toString();
		
		 StringBuilder  sb1 = new  StringBuilder(s1);
	
		 
		 StringBuilder sb2 =  new  StringBuilder(sb1.reverse()) ;
		String s2= sb2.toString();
		
		 if(s1.equals(s2)) {
			
			 return true;
		 }
		 
		 return false;
	    }
	
	
}
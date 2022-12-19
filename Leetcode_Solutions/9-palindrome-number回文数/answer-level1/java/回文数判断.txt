### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPalindrome(int num) {
         long result = 0;
         int sourceNum = num;
         boolean isPalindrome = false;
         if(num < 0){
        	return  isPalindrome;
         }
         if(num >= Math.pow(2, 31) * -1 &&  num <= Math.pow(2, 31) - 1){
        	 //TODO 1、取余
        	 while(num != 0){
        		 result = result * 10 + num % 10;
        		 num = num / 10;
        	 }
        	 
        	 if(result <   ((Math.pow(2, 31)) * -1) || result > (Math.pow(2, 31)) - 1) {
        		 result = 0;
        	 }
         }
         
         if((int)result == sourceNum){
             isPalindrome = true;
         }
         return isPalindrome;
    }
}
```
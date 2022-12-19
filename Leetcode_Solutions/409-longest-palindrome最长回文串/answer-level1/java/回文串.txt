### 解题思路
此处撰写解题思路
1，了解集合的概念，数组的运用，三目运算符的合理使用；
2，静态的static的使用；
3，了解最长的回文串：就是前后读的字母是一样的，比如level 和 noon ；
4，算法：定义一个数组以及范围；
        使用循环来记录字符串中重复的单词数；
        若重复的单词等于2的倍数，则用来记录的自增1；
        因为2的倍数的单词可以在字符串的前后各放2的n次方，这样就可以组成最长的回文串；
### 代码

```java
class Solution {
    public static int longestPalindrome(String s) 
	   {
	        int[] count = new int[128];
	        int max = 0;
	        //计算重复的个数
	        for(char c: s.toCharArray())
	        {
	            if (++count[c] == 2)
	            {
	                max ++;
	                count[c] = 0;
	            }
	        }
	        max *= 2;
	        return max < s.length() ? ++max : max;
	    }
}
```
### 解题思路

也是比较经典的题，解法也比较常见，要么借助 StringBuilder，要么就双指针

本题题目要求原地修改，当我借助 StringBuilder 时在eclipse中可以通过的用例在这里不行，下面也会贴出代码，和其他题不同的是，本题输入是一个 char 数组，输出也是 ，用sb的时候需要变化几次，但还是一行就可以了

``` java
class Solution {
    public void reverseString(char[] s) {
        s = new StringBuilder(new String(s)).reverse().toString().toCharArray();
    }
}
```


双指针是可以解决的，而且正是原地修改，代码如下：

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        int i = 0;
		int j = s.length-1;
		while (i <= j) {
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			i++;
			j--;
			
		}
    }
}
```
### 解题思路


执行用时 :1 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :45.4 MB, 在所有 java 提交中击败了93.78%的用户

终于写了一个高效的代码了，舒服了。把原答案的if判断改由 `>>`来代替，代码简洁不少，但是可能不好理解。

此处撰写解题思路

### 优化后代码


```java
class Solution {
    public void reverseString(char[] s) {

		for (int i = 0 ; i < s.length >> 1; i++) {
			char m  = s[i];
			s[i] = s[s.length-i-1];
			s[s.length-1-i]  = m;
            
		}
    }
}
```


### 优化前代码

```java
class Solution {
    public void reverseString(char[] s) {
        int l = s.length;
		char m = 0;
		
		if (l%2 == 0) {
			l = l/2;
		}else {
			l = (l+1)/2;
		}
		
		for (int i = 0 ; i < l; i++) {
			m  = s[i];
			s[i] = s[s.length-i-1];
			s[s.length-1-i]  = m;
		}
    }
}


```
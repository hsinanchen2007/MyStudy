### 解题思路

![IMG_0463.PNG](https://pic.leetcode-cn.com/e2c3c17825abf895a6f01c997060425abe43119f9e7197b73b033e2eddcff893-IMG_0463.PNG)


### 代码

巧法：

```java
class Solution {
 public boolean detectCapitalUse(String word) {
      return  word.equals(word.toLowerCase())||word.equals(word.toUpperCase())
      ||word.equals(Character.toUpperCase(word.charAt(0))+word.substring(1).toLowerCase());
    }
}
```
常规方法：
```java
class Solution {
    public boolean detectCapitalUse(String word) {
        char a[] = word.toCharArray();
		int len = a.length;
		int dd = 0,dx = 0;
		
		// 大写
		if(a[0]>=65 && a[0]<=90) {
			for(int i=1;i<len;i++) {
				if(a[i]>=65 && a[i]<=90) dd++;
				else dx++;
			}
			return dd==a.length-1 || dx==a.length-1;
		}
		if(a[0]>=97 && a[0]<=122) {
			for(int i=1;i<len;i++) {
				if(a[i]>=65 && a[i]<=90) return false;
			}
			return true;
		}
		return false;
    }
}
```
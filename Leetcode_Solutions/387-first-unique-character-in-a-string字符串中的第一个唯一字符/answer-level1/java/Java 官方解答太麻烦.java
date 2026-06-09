### 解题思路

![IMG_0458.PNG](https://pic.leetcode-cn.com/89bcecc1b0bf1957d24077ee33eb913d02c30beba58b1844dac78fc23254f9d5-IMG_0458.PNG)



### 代码

```java
class Solution {
    public int firstUniqChar(String s) {
        for(char c:s.toCharArray()) {
    		if(s.indexOf(c)==s.lastIndexOf(c)) return s.indexOf(c);
    	}
    	return -1;
    }
}
```